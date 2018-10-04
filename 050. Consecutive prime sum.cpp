/*
The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?
*/
// Completed on Sat, 14 Oct 2017
#include <iostream>
using namespace std;

bool prime;
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
int main() {
	int n = 0;
	int primes[100000];
	for (int i = 2; i < 11; i++) {
		if (isPrime(i)) {
			primes[n] = i;
			n++;
		}
	}
	for (int i = 11; i < 1000000; i++) {
		if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 10 == 0) {
			continue;
		}
		if (isPrime(i)) {
			primes[n] = i;
			n++;
		}
	}
	int x=0;
	int count;
	int max = 0;
	int prim;
	for (int i = 0; i < n; i++) {
		count = 0;
		x = 0;
		for (int j = i; j < n; j++) {
			x += primes[j];
			if (x > 999999) {
				break;
			}
			count++;
			if (isPrime(x)) {
				if (count > max) {
					max = count;
					prim = x;
				}
			}
		}
	}
	cout << prim << " " << max << endl;
	system("pause");
	return 0;
}