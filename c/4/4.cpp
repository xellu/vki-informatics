//#include <stdio.h>
//#include <random>
//
//int main() {
//	int arr[30];
//	int n = rand() % 50;
//	int m = rand() % 50;
//
//	for (int i = 0; i < 30; i++) {
//		if (i % 3 == 1) {
//			arr[i] = rand() % 50;
//			continue;
//		}
//
//		arr[i] = -1;
//		
//	}
//
//	printf("n = %i\n", n);
//	printf("m = %i\n\n", m);
//	for (int i = 0; i < 30; i++) {
//		if (i % 3 != 1) continue;
//		printf("%d, ", arr[i]);
//	}
//	printf("\n");
//
//	for (int i = 0; i < 30; i++) {
//		if (i % 3 != 1) continue;
//
//		if (arr[i] > n) {
//			arr[i - 1] = n;
//		}
//		if (arr[i] < m) {
//			arr[i + 1] = m;
//		}
//	}
//
//	for (int i = 0; i < 30; i++) {
//		if (arr[i] == -1) continue;
//		printf("%d, ", arr[i]);
//	}
//}