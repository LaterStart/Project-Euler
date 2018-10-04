/*
It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.

9 = 7 + 2×12
15 = 7 + 2×22
21 = 3 + 2×32
25 = 7 + 2×32
27 = 19 + 2×22
33 = 31 + 2×12

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/
// Completed on Wed, 11 Oct 2017
#include <iostream>
using namespace std;

bool odd, prime;
bool isOddComposite(int n) {
	odd = false;
	if (n % 2 != 0) {
		for (int i = 3; i < n; i++) {
			if (n%i == 0) {
				odd = true;
				break;
			}
		}
	}
	return odd;
}
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
	const int N = 10000;
	int x;
	bool check, breakme;
	int k;
	int odds[N];
	int n = 0;
	for (int i = 2; i <= N; i++) {
		if (isOddComposite(i)) {
			odds[n] = 0;
			breakme = false;
			for (int j = 3; j < i-1; j++) {
				if (isPrime(j)) {
					x = 0;
					check = false;
					for (k = 1; x < i; k++) {
						x = j + (2 * (pow(k, 2)));
						if (x == i) {
							check = true;
							breakme = true;
							break;
						}
					}
					if (check) {
						odds[n] += 1;
					}
				}
				if (breakme) {
					break;
				}
			}
			if (odds[n] == 0) {
				cout << i << endl;
			}
		}
		n++;
	}
	system("pause");
	return 0;
}