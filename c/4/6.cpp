//#include <stdio.h>
//#include <random>
//
//void printArray(int arr[], int size) {
//	for (int i = 0; i < size; i++) {
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main() {
//	int arr[16];
//
//	for (int i = 0; i < 16; i++) {
//		arr[i] = rand() % 20;
//	}
//
//	int size = sizeof(arr) / sizeof(arr[0]);
//	printArray(arr, size);
//
//	int i, j, k;
//
//	for (i = 0; i < size; i++) {
//		for (j = i + 1; j < size; ) {
//			if (arr[i] == arr[j]) {
//				for (k = j; k < size - 1; k++) {
//					arr[k] = arr[k + 1];
//				}
//				size--;
//			}
//			else {
//				j++;
//			}
//		}
//	}
//
//	printArray(arr, size);
//
//}