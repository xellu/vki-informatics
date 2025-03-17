num = abs(int(input("num=")))

last = 10
out = True

if (str(num)[0] > str(num)[1]): out = False

while num > 10:
    current = num % 10
    if current > last:
        out = False

    last = current
    num //= 10

print("YES" if out else "NO")