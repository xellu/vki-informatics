#include <stdio.h>
#include <random>
#include <iostream>

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	system("chcp 1251");

	int arr[16];
	
	for (int i = 0; i < 16; i++) {
		arr[i] = rand() % 20;
	}

	int size = sizeof(arr) / sizeof(arr[0]);
	printArray(arr, size);

	int peak = -1;

	for (int i = 1; i < size - 1; i++) {
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
			peak = i;
		}
	}

	if (peak != -1) {
		printf("\n%d, %d, %d\n", arr[peak-1], arr[peak], arr[peak+1]);
		printf("эл. переп последней 'пиковой' тройкой: ");
		printArray(arr, peak-1);
	}
	else {
		printf("нет подходящих");
	}

}