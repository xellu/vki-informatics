
def abc(a, b, c):
    if a != b or b != c or a != c:
        highest = max([a,b,c])

        return a+b+c-highest

    a, b, c = 0, 0, 0
    return a, b, c

print(
    abc(
        int(input("a=")),
        int(input("b=")),
        int(input("c="))
    )
)
