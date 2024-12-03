import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session, url_for
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

from datetime import datetime

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    tables = db.execute(
        "SELECT symbol, shares FROM portfolio WHERE user_id = ?", session["user_id"])
    for table in tables:
        table["price"] = lookup(table["symbol"])["price"]
        table["total"] = table["price"] * table["shares"]
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    total = sum(lookup(table["symbol"])["price"] * table["shares"]
                for table in tables) + cash[0]['cash']
    return render_template("index.html", tables=tables, cash=cash, lookup=lookup, total=total)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("please type in a symbol")
        if not request.form.get("shares").isdigit():
            return apology("not a valid number")
        if not int(request.form.get("shares")) > 0:
            return apology("not a valid number")

        stock = lookup(request.form.get("symbol"))
        if stock:
            price_all = stock["price"] * int(request.form.get("shares"))
            remain_money = db.execute("SELECT cash FROM users WHERE id = ?",
                                      session["user_id"])[0]["cash"]
            if remain_money >= price_all:
                remain_money -= price_all
                rows = db.execute("SELECT * FROM portfolio WHERE symbol = ?", stock["symbol"])
                db.execute("INSERT INTO transactions (user_id, symbol, shares, price, timestamp) VALUES (?, ?, ?, ?, ?)",
                           session["user_id"], request.form.get("symbol"), int(request.form.get("shares")), int(stock["price"]), datetime.now())
                if len(rows) > 0:
                    db.execute("UPDATE portfolio SET shares = shares + ?",
                               request.form.get("shares"))
                else:
                    db.execute("INSERT INTO portfolio (user_id, symbol, shares) VALUES (?, ?, ?)",
                               session["user_id"], stock["symbol"], request.form.get("shares"))
                db.execute("UPDATE users SET cash = ? WHERE id = ?",
                           remain_money, session["user_id"])
                return redirect(url_for("index"))
            else:
                return apology("you do not have enough money!")
        else:
            return apology("not a valid symbol")
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    rows = db.execute("SELECT * FROM transactions WHERE user_id = ?", session["user_id"])
    return render_template("history.html", rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        if not request.form.get("symbol"):
            return apology("not a valid symbol")

        stock = lookup(request.form.get("symbol"))

        if stock:
            return render_template("quoted.html", name=stock["name"], price=stock["price"], symbol=stock["symbol"])
        return apology("not a valid symbol")
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        elif not request.form.get("confirmation"):
            return apology("must provide password again", 400)

        elif request.form.get("password") != request.form.get("confirmation"):
            return apology("two passwords are not the same", 400)

        # Ensure username exists and password is correct
        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", request.form.get(
                "username"), generate_password_hash(request.form.get("password"), method='scrypt', salt_length=16))
        except:
            return apology("User is already existed. Return to log in!", 400)

        # Remember which user has logged in
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "GET":
        stocks = db.execute("SELECT symbol FROM portfolio WHERE user_id = ?", session["user_id"])
        return render_template("sell.html", stocks=stocks)
    else:
        if not request.form.get("shares"):
            return apology("type in the shares")
        elif int(request.form.get("shares")) <= 0:
            return apology("invalid shares", 403)
        elif not request.form.get("symbol"):
            return apology("select a valid symbol")
        stock = db.execute("SELECT * FROM portfolio WHERE user_id = ? AND symbol = ?",
                           session["user_id"], request.form.get("symbol"))
        table = lookup(request.form.get("symbol"))
        price = table["price"]
        person = db.execute("SELECT * FROM users WHERE id = ?", session["user_id"])
        if int(stock[0]["shares"]) - int(request.form.get("shares")) >= 0:
            db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", price *
                       int(request.form.get("shares")), session["user_id"])
            db.execute("UPDATE portfolio SET shares = shares - ? WHERE user_id = ? AND symbol = ?",
                       int(request.form.get("shares")), session["user_id"], request.form.get("symbol"))
            db.execute("INSERT INTO transactions (user_id, symbol, shares, price, timestamp) VALUES (?, ?, ?, ?, ?)",
                       session["user_id"], request.form.get("symbol"), -int(request.form.get("shares")), int(price), datetime.now())
            if int(stock[0]["shares"]) - int(request.form.get("shares")) == 0:
                db.execute("DELETE FROM portfolio WHERE user_id = ? AND symbol = ?",
                           session["user_id"], request.form.get("symbol"))
        else:
            return apology("you don not have enough shares")
        stocks = db.execute("SELECT symbol FROM portfolio WHERE user_id = ?", session["user_id"])
        return redirect(url_for("index"))


@app.route("/change_psw", methods=["GET", "POST"])
@login_required
def change_psw():
    if request.method == "GET":
        return render_template("change_psw.html")
    if not request.form.get("original") or not request.form.get("changed"):
        return apology("enter your password")
    table = db.execute("SELECT hash FROM users WHERE id = ?", session["user_id"])
    if not check_password_hash(table[0]["hash"], request.form.get("original")):
        return apology("not matched")
    db.execute("UPDATE users SET hash = ? WHERE id = ?", generate_password_hash(
        request.form.get("changed"), method='scrypt', salt_length=16), session["user_id"])
    return render_template("change_psw.html")
