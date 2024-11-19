from cs50 import get_string

str = get_string("Text: ")

W = 1
L = 0
S = 0
for c in str:
    if c == "." or c == "!" or c == "?":
        S += 1
    elif c == " ":
        W += 1
    elif c.isalpha():
        L += 1

L = L / W * 100
S = S / W * 100

cl = 0.0588 * L - 0.296 * S - 15.8

cl_int = round(cl)

if cl_int >= 16:
    print("Grade 16+")
elif cl_int < 1:
    print("Before Grade 1")
else:
    print(f"Grade {cl_int}")
