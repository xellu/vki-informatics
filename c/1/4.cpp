//#include <stdio.h>
//
//int main() {
//	int num, sum, product;
//
//	printf("4-digit number: ");
//	scanf_s("%d", &num);
//
//	if (num < 1000 || num > 9999) {
//		printf("number is not 4 digits long");
//		return 1;
//	}
//
//	int d1 = num / 1000;
//	int d2 = (num / 100) % 10;
//	int d3 = (num / 10) % 10;
//	int d4 = num % 10;
//
//	sum = d1 + d2 + d3 + d4;
//	product = d1 * d2 * d3 * d4;
//
//	printf("sum=%i, product=%i", sum, product);
//
//	return 0;
//}