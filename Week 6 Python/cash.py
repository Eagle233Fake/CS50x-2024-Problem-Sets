from cs50 import get_float

while True:
    n = get_float("Change owed: ") * 100
    if n >= 0:
        break

counter = 0

n_25 = n
while n_25 >= 25:
    n_25 -= 25
    counter += 1

n_10 = n_25
while n_10 >= 10:
    n_10 -= 10
    counter += 1

n_5 = n_10
while n_5 >= 5:
    n_5 -= 5
    counter += 1

n_1 = n_5
while n_1 >= 1:
    n_1 -= 1
    counter += 1

print(counter)
