import random

N = [random.randint(40, 80) for _ in range(10)]
print(N)

for num in N.copy():
    value = 0
    for char in str(num):
        value += int(char)

    print(f"{num=} {value=} {value%2!=0}")

    if value % 2 == 0:
        N.remove(num)

print(N)