/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28,
which means that 28 is a perfect number.
A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.
As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/
// Completed on Mon, 18 Sep 2017
#include <iostream>
using namespace std;

int main() {
	const int limit = 28123;

	unsigned int sum = 0;
	unsigned long long SUM1 = 0;
	unsigned long long SUM2 = 0;
	unsigned int FINAL;
	int abdundant[6965];

	bool numbers[limit] = { 0 };
	int k = 0;
	for (int i = 12; i <= limit; i++) {
		for (int j = 1; j < i; j++) {
			if (i%j == 0) {
				sum += j;
			}
		}
		if (sum > i) {
			abdundant[k] = i;
			k++;
		}
		sum = 0;
	}
	cout << k << endl;
	for (int i = 0; i < k; i++) {
		for (int j = i; j < k; j++) {
			if (abdundant[i] + abdundant[j] > limit) {
				break;
			}
			else {
				numbers[abdundant[i] + abdundant[j]] = true;
			}
		}
	}
	for (int i = 0; i <= limit; i++) {
		if (numbers[i] == 1) {
			SUM1 += i ;
		}
	}
	cout << SUM1 << endl;
	for (int i = 1; i <= limit; i++) {
		SUM2 += i;
	}
	FINAL = SUM2 - SUM1;
	cout << FINAL << endl;

	system("Pause");
	return 0;
}