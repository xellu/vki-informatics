//#include <stdio.h>
//
//int main() {
//	int d1, d2, d3, d4, in;
//
//	printf("enter a number (0-9999)> ");
//	scanf_s("%d", &in);
//
//	d1 = in / 1000;
//	d2 = (in / 100) % 10;
//	d3 = (in / 10) % 10;
//	d4 = in % 10;
//
//	if (d1 == d4 && d2 == d3) {
//		printf("the number IS a palindrome");
//		return 0;
//	}
//
//	printf("the number is NOT a palindrome");
//	return 0;
//}