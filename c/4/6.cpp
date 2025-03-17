#include <stdio.h>
#include <random>

int main() {
	int arr[16];

	for (int i = 0; i < 16; i++) {
		arr[i] = rand() % 20;
	}

}