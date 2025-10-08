#include<stdio.h>

int main() {
	int num, numIndex = 0;

	printf("num> ");
	scanf("%d", &num);

	int nums[99];

	while (true) {
		nums[numIndex] = num % 10;
		num = num / 10;

		if (num == 0) { break; }
		numIndex++;
	}

	int min = 999, max = 0;
	int minIndex = 0, maxIndex = 0;

	for (int i = 0; i < numIndex; ++i) {
		if (nums[i] < min) { 
			min = nums[i];
			minIndex = i;
		}
		if (nums[i] > max) {
			max = nums[i];
			maxIndex = i;
		}
	}

	printf("max=%i, min=%i", max, min);
	if (minIndex > maxIndex) {
		printf("min digit");
		return 0;
	}
	printf("max digit");

	return 0;
}