import math

PI = 3.14

circle_radius = int(input("r="))
square_side = int(input("a="))

surface_circle = PI*(circle_radius**2)
surface_square = square_side**2

if math.sqrt(surface_square) > math.sqrt(surface_circle/PI):
    print("square won't fit")
else:
    print("square will fit")
