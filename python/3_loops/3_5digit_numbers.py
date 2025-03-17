num = int(input("num>"))

if len(str(num)) < 5:
    while len(str(num)) != 5:
        num = f"0{num}"
print(str(num)[:5])
