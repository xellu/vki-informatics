#include <stdio.h>

int main() {
	int nowYr, nowMo, bornYr, bornMo;

	printf("Current Date (month.year): ");
	scanf("%d.%d", &nowMo, &nowYr);

	printf("Date of Birth (month.year): ");
	scanf("%d.%d", &bornMo, &bornYr);

	int age = nowYr - bornYr;
	if (nowMo < bornMo) { age--; }

	printf("You're %i years old", age);
	return 0;
}