/*
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms increases by 3330, is unusual in two ways: (i) each of the three terms are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?
*/
// Completed on Sat, 14 Oct 2017
#include <iostream>
#include <string>
using namespace std;

bool prime;
int diff;
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
bool differentDigits(string n){
	diff = 0;
	for (int i = 0; i < n.length(); i++) {
		for (int j = 0; j < n.length(); j++) {
			if (i != j && n[i] == n[j]) {
				diff += 1;
				break;
			}
		}
	}
	if (diff == 0 || diff == 1 || diff == 2) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int n = 0;
	int primes[2000];
	int increase = 3330;
	for (int i = 1000; i < 10000; i++) {
		if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 10 == 0) {
			continue;
		}
		if (isPrime(i)) {
			primes[n] = i;
			n++;
		}
	}
	string a, b, c;
	int check;
	for (int i = 0; i < n; i++) {
		if (((primes[i] + increase) + increase) > 9999) {
			continue;
		}
		a = to_string(primes[i]);
		if (!differentDigits(a)) {
			continue;
		}
		if (isPrime(primes[i] + increase)) {
			b = to_string(primes[i] + increase);
			if (!differentDigits(b)) {
				continue;
			}
			check = 0;
			for (int i = 0; i < a.length(); i++) {
				for (int j = 0; j < b.length(); j++) {
					if (a[i] == b[j]) {
						check++;
						break;
					}
				}
			}
			if (check < 4) {
				continue;
			}
			if (isPrime((primes[i] + increase) + increase)) {
				c = to_string((primes[i] + increase) + increase);
				if (!differentDigits(c)) {
					continue;
				}
				check = 0;
				for (int i = 0; i < b.length(); i++) {
					for (int j = 0; j < c.length(); j++) {
						if (b[i] == c[j]) {
							check++;
							break;
						}
					}
				}
				if (check < 4) {
					continue;
				}
				cout << a << " " << b << " " << c << " " << increase << endl;
			}
		}
	}
	system("pause");
	return 0;
}