/*
Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ? 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 3 fractions between 1/3 and 1/2.

How many fractions lie between 1/3 and 1/2 in the sorted set of reduced proper fractions for d ? 12,000?
*/
// Completed on Fri, 15 Dec 2017
#include <iostream>
using namespace std;

//Euclid's algorithm
unsigned int HCF(unsigned int a, unsigned int b) {
	unsigned int quotient;
	unsigned int reminder;
	unsigned int tmp;

	quotient = a / b;
	reminder = a % b;

	while (reminder > 0) {
		tmp = reminder;
		quotient = b / reminder;
		reminder = b % reminder;
		b = tmp;
	}
	return b;
}

int main() {
	unsigned int limit = 12000;
	
	double x = static_cast<double>(1) / static_cast<double>(2);
	double y = static_cast<double>(1) / static_cast<double>(3);

	unsigned int count = 0;
	for (int i = limit; i >= 1; i--) {
		for (int j = limit; (j > i && j >=1); j--) {			
			if (HCF(i, j) == 1) {
				if ((static_cast<double>(i) / static_cast<double>(j)) <= y) continue;
				if ((static_cast<double>(i) / static_cast<double>(j)) >= x) continue;
				count++;			
			}
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}