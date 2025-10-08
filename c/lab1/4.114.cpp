#include <stdio.h>

int getDays(int mo, int yr) {
	if (mo == 2) {
		return yr % 4 ? 29 : 28;
	}

	return mo % 2 == 0 ? 30 : 31;
}

void printNext(int day, int mo, int yr) {
	day++;
	
	if (day > getDays(mo, yr)) {
		day = 1;
		mo++;
		if (mo > 12) {
			mo = 1;
			yr++;
		}
	}
	printf("Next Day: %i.%i.%i\n", day, mo, yr);
}

void printPrev(int day, int mo, int yr) {
	day--;

	if (day <= 0) {
		mo--;
		if (mo <= 0) { 
			yr--;
			mo = 12;
		}
		day = getDays(mo, yr);
	}

	printf("Previous Day: %i.%i.%i\n", day, mo, yr);
}

int main() {
	int day, mo, yr;

	printf("Date (dd.mm.yyyy): ");
	scanf("%d.%d.%d", &day, &mo, &yr);

	printNext(day, mo, yr);
	printPrev(day, mo, yr);

	return 0;
}