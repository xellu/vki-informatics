#include <stdio.h>
#include <random>

int main() {
	const int sizeA = 12;
	const int sizeB = 16;

	int arrA[sizeA];
	int arrB[sizeB];

	for (int i = 0; i < sizeA; i++) {
		arrA[i] = rand() % 20;
	}

	for (int i = 0; i < sizeB; i++) {
		arrB[i] = rand() % 20;
	}



	//printf("%i, %i", sizeof(arrA)/4, sizeof(arrB)/4);

	if (sizeof(arrA) >= sizeof(arrB)) {
		printf("true - arrB can fit into arrA");
		return 0;
	}

	int diff = (sizeof(arrB) - sizeof(arrA)) / 4;

	printf("false - ");
	for (int i = 0; i < diff; i++) {
		printf("%i ", arrB[sizeof(arrB) / 4 - diff + i]);
	}
}