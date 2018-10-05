/*Consider the divisors of 30: 1,2,3,5,6,10,15,30.
It can be seen that for every divisor d of 30, d+30/d is prime.

Find the sum of all positive integers n not exceeding 100 000 000
such that for every divisor d of n, d+n/d is prime.*/
// Completed on Tue, 7 Nov 2017
#include <iostream>
#include <string>
using namespace std;

bool prime;
bool check;
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

bool primeDivisors(int n) {
	int i = 0;
	check = false;
	if (isPrime(n + 1)) {
		check= true;
		for (int i = sqrt(n); i >=1; i--) {
			if (n%i == 0) {
				if (!isPrime(n / i + i)) {
					return false;
				}
			}
		}
	}
	return check;
}

bool uneven(int i) {
	if (i % 2 != 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	unsigned long long SUM = 0;
	for (int i = 1; i <= 100000000; i++) {
		if (i % 10 == 2) {
			if (!uneven((i % 100)/10)) {
				if (primeDivisors(i)) {
					SUM += i;
				}
			}
		}
		else if (i % 10 == 0 || i % 10 == 8) {
			if (uneven((i % 100)/10)) {
				if (primeDivisors(i)) {
					SUM += i;
				}
			}
		}
	}
	SUM += 7;
	cout << SUM<< endl;
	system("pause");
	return 0;
}