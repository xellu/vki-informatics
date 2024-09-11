num = int(input("num="))

summ = 1
prod = 1


for i in range(4):
    x = num % 10

    summ += x
    prod *= x

    num = num//10

print(f"{summ=},{prod=}")
