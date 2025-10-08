//#include <stdio.h>
//
//int main() {
//	int d[4], in;
//
//	printf("enter a number (0-9999)> ");
//	scanf_s("%d", &in);
//
//	d[0] = in / 1000;
//	d[1] = (in / 100) % 10;
//	d[2] = (in / 10) % 10;
//	d[3] = in % 10;
//
//	int nums[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//
//	for (int i = 0; i < 4; ++i) {
//		nums[d[i]]++;
//	}
//
//	for (int i = 0; i < 10; ++i) {
//		if (nums[i] == 3) {
//			printf("Yes");
//			return 0;
//		}
//	}
//
//	printf("No");
//	return 0;
//}