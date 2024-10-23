class coords:
    def __init__(self, x, y):
        self.x = x
        self.y = y

a = coords(0, 0)
b = coords(7, 7)

lenX = abs(a.x - b.x)
lenY = abs(a.y - b.y)

surface = lenX * lenY
perimeter = (lenX + lenY) * 2

print(f"{surface=}")
print(f"{perimeter=}")
