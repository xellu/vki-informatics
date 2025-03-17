#create f1.txt, write N*3 amount of integers

import math
import json

class Circle:
    def __init__(self, x, y, r):
        self.x = x
        self.y = y
        self.r = r

    def calculate(self):
        perimeter = self.r*2*math.pi
        area = self.r**2*math.pi

        return {
            "x": self.x,
            "y": self.y,
            "radius": self.r,
            "perimeter": perimeter,
            "area": area
        }

f1 = open("f1.txt", "r")
f2 = open("f2.txt", "w")

data = f1.read().splitlines()
f1.close()

circles = []
main_circle = None

for offset in range(int(len(data)/3)):
    c = Circle(int(data[offset*3]), int(data[offset*3+1]), int(data[offset*3+2]))

    if main_circle is None:
        main_circle = c
    else:
        circles.append(c)

out = [main_circle.calculate()]
for c in circles:
    distance = math.sqrt(c.x**2 + c.y**2)
    if distance <= c.r+main_circle.r:
        print(f"Circle at x={c.x}, y={c.y} intersects with primary circle")
        out.append(c.calculate())

f2.write(json.dumps(out, indent=4))