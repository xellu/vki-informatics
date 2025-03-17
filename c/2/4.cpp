#include <stdio.h>
#include <iostream>

int main() {
	system("chcp 1251");

	int rX = 2;
	int rY = 6;

	int qX = 4;
	int qY = 1;

	int tX = 2;
	int tY = 3;


	int queen = qX == tX || qY == tY || (abs(tX - qX) == abs(tY - qY));
	int rook = (rX == tX || rY == tY);

	//printf("r=%i, q=%i", rook, queen);
	if (rook && queen) {
		printf("да - под ударом");
	}
	else if (rook) {
		printf("да");
	}
	else {
		printf("нет");
	}
}