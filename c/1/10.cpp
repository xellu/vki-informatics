#include <stdio.h>
#include <math.h>

int main() {
	int aX = 2;
	int aY = 5;

	int cX = 5;
	int cY = 8;

	int lenX = abs(aX - cX);
	int lenY = abs(aY - cY);

	int perimeter = (lenX + lenY) * 2;
	int surface = lenX * lenY;

	printf("a(x=%i, y=%i), c(x=%i, y=%i)\n", aX, aY, cX, cY);
	printf("perimeter=%i \nsurface=%i", perimeter, surface);
}