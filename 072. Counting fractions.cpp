/*
Consider the fraction, n/d, where n and d are positive integers. If n<d and HCF(n,d)=1, it is called a reduced proper fraction.

If we list the set of reduced proper fractions for d ? 8 in ascending order of size, we get:

1/8, 1/7, 1/6, 1/5, 1/4, 2/7, 1/3, 3/8, 2/5, 3/7, 1/2, 4/7, 3/5, 5/8, 2/3, 5/7, 3/4, 4/5, 5/6, 6/7, 7/8

It can be seen that there are 21 elements in this set.

How many elements would be contained in the set of reduced proper fractions for d ? 1,000,000?
*/
// Completed on Tue, 19 Dec 2017
#include <iostream>
#include <iomanip>
using namespace std;

const unsigned int limit = 1000000;
bool *primeCheck = new bool[limit+1]();
unsigned long long primesList[limit+1];
unsigned long long *totient = new unsigned long long[limit+1]();

void sieve() {
	double root = sqrt(limit);
	for (unsigned long long n = 4; n <= limit; n += 2) {
		primeCheck[n] = true;
	}
	for (unsigned long long n = 3; n <= root; n += 2) {
		if (!primeCheck[n]) {
			for (unsigned long long m = n * n; m <= limit; m += (2 * n)) {
				primeCheck[m] = true;
			}
		}
	}
	unsigned long long count = 0;
	for (unsigned long long i = 2; i <= limit; i++) {
		if (!primeCheck[i]) {
			primesList[++count] = i;
		}
	}
	primesList[0] = count;
}

void totientPrimePowers() {
	unsigned long long n = primesList[0];
	unsigned long long  x;
	unsigned long long  y;
	for (unsigned long long i = 1; i <= n; i++) {
		y = primesList[i];
		for (unsigned long long j = 1; ; j++) {
			x = pow(y, j);
			if (x > limit) break;
			totient[x] = x - pow(y, j - 1);
		}
	}
}

void totientSemiPrimes() {
	unsigned long long n = primesList[0];
	unsigned long long x;
	for (unsigned long long i = 1; i <= n; i++) {
		for (unsigned long long j = i + 1; j <= n; j++) {
			x = primesList[i] * primesList[j];
			if (x > limit)break;
			totient[x] = (primesList[i] - 1)*(primesList[j] - 1);
		}
	}
}

unsigned long long totientComposite(unsigned long long n) {
	unsigned long long p, x = 1;
	for (unsigned long long i = 1; i <= primesList[0]; i++) {
		if (n % primesList[i] == 0) {
			p = 1;
			while (n % primesList[i] == 0) {
				n /= primesList[i];
				p *= primesList[i];
			}
			x *= totient[p];
		}
		if (n == 1) return x;
	}
}

int main() {
	sieve();
	totient[1] = 1;
	totientPrimePowers();
	totientSemiPrimes();

	for (unsigned long long i = 2; i <= limit; i++) {
		if (totient[i] == NULL) {
			totient[i] = totientComposite(i);
		}
	}		
	unsigned long long sum = 0;
	for (unsigned long long i = 2; i <= limit; i++) {
		sum += totient[i];		
	}
	
	cout << sum << endl;
	system("pause");
	return 0;
}