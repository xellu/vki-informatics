import math

class coords:
    def __init__(self, x, y):
        self.x = x
        self.y = y

m1 = coords(0, 0)
m2 = coords(4, 3)

distanceX = m1.x - m2.x
distanceY = m1.y - m2.y

distance = math.sqrt(distanceX**2) + math.sqrt(distanceY**2)
print(distance)
