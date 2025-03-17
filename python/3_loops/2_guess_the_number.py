import random

num = random.randint(1, 25)
max_attempts = 5

print(f"{num=}")
for i in range(max_attempts):
    guess = int(input("your guess>"))

    if guess == num:
        print("you won")
        break

    print(("higher" if num > guess else "lower") + f" - {max_attempts-i} attemps remaining\n")

else:
    print("you lost")
