//#include <stdio.h>
//#include <iostream>
//
//int main() {
//	system("chcp 1251");
//
//	int nums[10];
//
//	for (int i = 0; i < 10; i++) {
//		printf("nums[%i] = ", i);
//		scanf_s("%d", &nums[i]);
//	}
//
//	int sum = 0;
//	int odd = 0;
//	int top[7];
//
//	for (int i = 0; i < 7; i++) {
//		top[i] = nums[i];
//	}
//
//	for (int i = 0; i < 10; i++) {
//		sum += nums[i];
//
//		if (nums[i] % 2 != 0) odd++;
//
//		for (int j = 0; j < 7; j++) {
//			printf("n=%i, t=%i\n", nums[i], top[j]);
//			if (top[j] < nums[i]) {
//				top[j] = nums[i];
//				break;
//			}
//		}
//
//	}
//
//	printf("сумма элементов: %i\n", sum);
//	printf("количество нечетных эл.: %i\n", odd);
//	printf("top 7: ");
//
//	for (int i = 0; i < 7; i++) {
//		printf("%d, ", top[i]);
//	}
//
//	return 0;
//}