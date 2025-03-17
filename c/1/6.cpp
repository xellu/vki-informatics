//#include <stdio.h>
//
//int main() {
//	int n, x;
//
//	printf("enter a number (10 <= n <= 999) and n / 10 % 10 != 0\n>");
//	scanf_s("%d", &n);
//
//	if (n < 10 || n > 999 || (n / 10) % 10 == 0) {
//		printf("invalid input");
//		return 1;
//	}
//
//	int b = n / 100;
//	int a = (n % 100) / 10;
//	int c = (n % 100) % 10;
//
//	x = a * 100 + b * 10 + c;
//
//	printf("x=%i", x);
//
//}