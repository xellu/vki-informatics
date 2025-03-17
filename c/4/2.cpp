//#include <stdio.h>
//
//int main() {
//	int nums[10];
//
//	for (int i = 0; i < 10; i++) {
//		printf("nums[%i] = ", i);
//		scanf_s("%d", &nums[i]);
//	}
//
//	int min, minIndex, max, maxIndex;
//
//	min = 99999;
//	max = -99999;
//
//	for (int i = 0; i < 10; i++) {
//		if (nums[i] < min) {
//			min = nums[i];
//			minIndex = i;
//		}
//
//		if (nums[i] > max) {
//			max = nums[i];
//			maxIndex = i;
//		}
//	}
//
//	for (int i = 0; i < 10; i++) {
//		printf("%i ", nums[i]);
//	}
//
//	printf("\n");
//
//	int temp = nums[maxIndex];
//	nums[maxIndex] = nums[minIndex];
//	nums[minIndex] = temp;
//
//	for (int i = 0; i < 10; i++) {
//		printf("%i ", nums[i]);
//	}
//
//	printf("\nmax=%i min=%i", max, min);
//
//
//}