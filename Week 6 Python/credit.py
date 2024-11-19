from cs50 import get_string

n = get_string("Number: ")

sum = 0

"""
for i in range(len(n)):
    i += 1
    digit = int(n[len(n) - 1 - i]) * 2
    if digit > 9:
        digit = 1 + digit - 10
    sum += digit

for i in range(len(n)):
    sum += int(n[len(n) - 1 - i])
    i += 1
"""
# Think why it doesn't work?

for i in range(len(n)):
    digit = int(n[len(n) - 1 - i])
    if i % 2 == 1:
        digit *= 2
        if digit > 9:
            digit = 1 + digit - 10
        sum += digit
    else:
        sum += int(n[len(n) - 1 - i])

if sum % 10 == 0:
    if n[0] == "5" and (n[1] == "1" or n[1] == "2" or n[1] == "3" or n[1] == "4" or n[1] == "5") and len(n) == 16:
        print("MASTERCARD")
    elif n[0] == "4" and (len(n) == 13 or len(n) == 16):
        print("VISA")
    elif n[0] == "3" and (n[1] == "4" or n[1] == "7") and len(n) == 15:
        print("AMEX")
    else:
        print("INVALID")
else:
    print("INVALID")
