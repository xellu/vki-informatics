year = int(input("enter a year: "))

if (year % 4 == 0 or year % 100 == 0) and not (year % 400 == 0):
    print(True)
else:
    print(False)
