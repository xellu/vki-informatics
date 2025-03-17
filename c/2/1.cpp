//#include <stdio.h>
//
//int main() {
//	int a, b, c, highest;
//
//	printf("a=");
//	scanf_s("%d", &a);
//
//	printf("b=");
//	scanf_s("%d", &b);
//
//	printf("c=");
//	scanf_s("%d", &c);
//
//	if (a != b || b != c || a != c) {
//		if (a > b && a > c) {
//			highest = a;
//		}
//		else if (b > a && b > c) { 
//			highest = b;
//		}
//		else {
//			highest = c;
//		}
//
//		printf("%i+%i+%i-%i=%i", a, b, c, highest, a + b + c - highest);
//		return 0;
//	}
//
//	a = 0;
//	b = 0;
//	c = 0;
//	printf("a=%i, b=%i, c=%i", a, b, c);
//}