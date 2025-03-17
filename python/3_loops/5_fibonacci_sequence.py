n = int(input("n="))

a = 0
b = 1
c = b
count = 1

out = []

while count <= n:
    out.append(c)

    count += 1

    a, b = b, c
    c = a + b
print(out)
