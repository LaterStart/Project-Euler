/*
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,
nCr = n! / r!(n-r)!
where r ? n
n! = n×(n-1)×...×3×2×1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 ? n ? 100, are greater than one-million?
*/
// Completed on Sat, 14 Oct 2017
#include <iostream>
using namespace std;

long double factorial(long double num) {
	long double factorial=1;
	for (int i = static_cast<int>(num); i > 0; i--) {
		factorial *= static_cast<long double>(i);
	}
	return factorial;
}

int main() {
	int count = 0;
	long double x;

	for (long double n = 23; n <= 100; n++) {
		for (long double r = 1; r <= n; r++) {
			x = factorial(n) / (factorial(r)*(factorial(n - r)));
			if (x > static_cast<long double>(1000000)) {
				count++;
			}			
		}
	}
	cout << count << endl;

	system("pause");
	return 0;
}