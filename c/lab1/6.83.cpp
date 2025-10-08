#include<stdio.h>

int main() {
	int num, a, numIndex = 0;

	printf("num> ");
	scanf("%d", &num);

	printf("a> ");
	scanf("%d", &a);

	int nums[99];

	while (true) {
		nums[numIndex] = num % 10;
		num = num / 10;

		if (num == 0) { break; }
		numIndex++;
	}

	int min = 999, max = 0;

	for (int i = 0; i < numIndex; i++) {
		if (nums[i] < min) { min = nums[i]; }
		if (nums[i] > max) { max = nums[i]; }
	}

	printf("max=%i, min=%i\n", max, min);
	printf("is divisible: %s", (max+min) % a == 0 ? "yes" : "no");

	return 0;
}