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
//	printf("%i%i%i%i", d3, d2, d1, d4);
//
//	return 0;
//}