//#include <stdio.h>
//#include <random>
//
//void calcMonth(char month) {
//	int days[31], sum = 0;
//	float avg;
//
//	for (int i = 0; i < 31; ++i) {
//		days[i] = rand() % (month == 'j' ? 50 : 20);
//		sum += days[i];
//	}
//
//	avg = sum / 31;
//	
//	printf("For %s: sum=%i, avg=%f\n", month == 'j' ? "January" : "March", sum, avg);
//}
//
//int main() {
//	calcMonth('j');
//	calcMonth('m');
//
//	return 0;
//}