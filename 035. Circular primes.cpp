/*
The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?
*/
// Completed on Sat, 7 Oct 2017
#include <iostream>
#include <string>
using namespace std;
bool prime;
bool isPrime(int n) {
	prime = true;
	for (int j = 2; j <= sqrt(n); j++) {
		if (n%j == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}
int main() {
	string primeStr;
	string tmp;
	bool circular;
	int n = 0;
	for (int i = 2; i < 1000000; i++) {
		if (isPrime(i)) {
			primeStr = to_string(i);
			circular = true;
			tmp = primeStr;
			for (int i = 0; i < primeStr.length(); i++) {
				for (int i = 0; i < primeStr.length() - 1; i++) {
					tmp[i] = primeStr[i + 1];
				}
				tmp[primeStr.length() - 1] = primeStr[0];
				primeStr = tmp;
				if (!isPrime(stoi(tmp))) {
					circular = false;
				}
			}
			if (circular) {
				cout << primeStr << endl;
				n++;
			}
		}
	}
	cout << n << endl;
	system("pause");
	return 0;
}