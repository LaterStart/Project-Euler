/*
Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ? 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that 2/5 is the fraction immediately to the left of 3/7.

By listing the set of reduced proper fractions for d ? 1,000,000 in ascending order of size, find the numerator of the fraction immediately to the left of 3/7.
*/
// Completed on Thu, 14 Dec 2017
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
	unsigned int limit = 1000000;
	unsigned int hcf;
	double x = static_cast<double>(7) / static_cast<double>(3) + 0.00001;
	double y = static_cast<double>(3) / static_cast<double>(7) + 0.000001;
	double z = static_cast<double>(3) / static_cast<double>(7) - 0.000001;
	double min = 0; int mem1, mem2;

	for (int i = limit; i >= 1; i--) {
		for (int j = i*x; (j > i && j<=limit); j--) {
			hcf = HCF(i, j);
			if (hcf == 1) {
				if ((static_cast<double>(i) / static_cast<double>(j)) > y) continue;
				if ((static_cast<double>(i) / static_cast<double>(j)) > z) {
					cout << i <<" "<<j<< endl;
					system("pause");
				}
			}
		}	
	}
	return 0;
}