#create f1.txt, write any N*4 amount of integers

import json

class Point2D:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def min_segment_length(self, p):
        lenX = abs(self.x - p.x)
        lenY = abs(self.y - p.y)

        return min([lenX, lenY])

f1 = open("f1.txt", "r")
f2 = open("f2.txt", "w")

data = f1.read().splitlines()
f1.close()

out = []

for offset in range(int(len(data)/4)):
    #print(f"starting point: {offset*4}")
    p1, p2 = Point2D(int(data[offset*4]), int(data[offset*4+1])), Point2D(int(data[offset*4+2]), int(data[offset*4+3]))

    msl = p1.min_segment_length(p2)
    print(f"p1={vars(p1)} p2={vars(p2)} - Min Length: {msl}")

    out.append({
        "p1": {
            "x": p1.x,
            "y": p1.y
        },
        "p2": {
            "x": p2.x,
            "y": p2.y
        },
        "min_segment_length": msl
    })

f2.write(json.dumps(out, indent=4))

