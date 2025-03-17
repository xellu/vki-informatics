//#include <stdio.h>
//
//int main() {
//	int num;
//
//	printf("enter a 5 digit number> ");
//	scanf_s("%d", &num);
//
//	if (num > 99999 || num < 1000) {
//		return 1;
//	}
//
//	int d1 = num / 10000;
//	int d2 = (num / 1000) % 10;
//	int d3 = (num / 100) % 10;
//	int d4 = (num / 10) % 10;
//	int d5 = num % 10;
//
//	if (d1 > 0) {
//		if (d1 == d5 && d2 == d4) {
//			printf("true");
//			return 0;
//		}
//	}
//	else {
//		if (d2 == d5 && d3 == d4) {
//			printf("true");
//			return 0;
//		}
//	}
//
//	printf("false");
//	return 0;
//}