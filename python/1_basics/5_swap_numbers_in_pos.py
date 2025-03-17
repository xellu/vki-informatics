num = int(input("num: "))

num = list(str(num))
num[0],num[2] = num[2], num[0]

num = int("".join(num))

print(f"{num=}")
