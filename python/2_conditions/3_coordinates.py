def is_in_area(x, y):
    if (x <= 0 and y <= 0) or (x > 0 and y <= x**2):
        return False

    return True

print( is_in_area( float(input("x=")), float(input("y=")),) )
