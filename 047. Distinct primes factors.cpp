/*
The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. What is the first of these numbers?
*/
// Completed on Fri, 13 Oct 2017
#include <iostream>
using namespace std;

bool prime;
int primes[100000];
bool isPrime(unsigned int n) {
	prime = true;
	for (unsigned int j = 2; j <= sqrt(n); j++) {
		if (n%j == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}
bool customPrimeFactorization(int n) {
	int count = 0;
	int mem = 0;
	int i = 0;
	while (n > 1) {
		if (n%primes[i] == 0) {
			n /= primes[i];	
			if (primes[i] > mem) {
				mem = primes[i];
				count++;
				if (count == 4) {
					break;
				}
			}
			if (n%primes[i] != 0) {
				i = 0;
			}
		}
		else {
			i++;
		}
	}
	if (n == 1 && count==4) {
		return true;
	}
	return false;
}
int main() {
	int n = 0;
	for (unsigned int i = 2; n < 100000; i++) {
		if (isPrime(i)) {
			primes[n] = i;
			n++;
		}
	}
	int first = 0;
	for (unsigned int i = 2; i < 1000000; i++) {
		if (isPrime(i)) {
			continue;
		}
		if (first==0) {
			if (customPrimeFactorization(i)) {
				first = i;
			}
		}		
		else {
			if (customPrimeFactorization(i) && customPrimeFactorization(i - 1) && customPrimeFactorization(i - 2) && customPrimeFactorization(i - 3)) {
				cout << first << endl;
				cout << i - 3 << endl;
				break;
			}
		}
		
	}
	system("pause");
	return 0;
}