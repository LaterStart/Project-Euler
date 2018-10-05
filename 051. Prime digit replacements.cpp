/*
By replacing the 1st digit of the 2-digit number *3, it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with the same digit, this 5-digit number is the first example having seven primes among the ten generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993. Consequently 56003, being the first member of this family, is the smallest prime with this property.

Find the smallest prime which, by replacing part of the number (not necessarily adjacent digits) with the same digit, is part of an eight prime value family.
*/
// Completed on Fri, 24 Nov 2017
#include <iostream>
#include <string>
using namespace std;

unsigned int N = pow(10, 6); unsigned int P = 0;
unsigned int * primesList = new unsigned int[N]();
bool * primesTable = new bool[N]();

void generatePrimeList() {
	for (unsigned int n = 11; n <= N; n++) {
		bool prime = true;
		for (unsigned int j = 2; j <= sqrt(n); j++) {
			if (n%j == 0) {
				prime = false;
				primesTable[n] = 0;
				break;
			}
		}
		if (prime) {
			primesList[P] = n;
			primesTable[n] = 1;
			P++; 
		}
	}
}

bool isPrime(unsigned int n) {
	if (primesTable[n] == 1) return true;
	if (primesTable[n] == 2) return false;
}

unsigned long long factorial(int n) {
	unsigned long long number = 1;
	for (int i = 1; i <= n; i++) {
		number *= i;
	}
	return number;
}

int combinations(int n, int r) {
	return (factorial(n)) / (factorial(r)*(factorial(n - r)));
}

int main() {
	string tmp1, tmp2;
	int count;
	generatePrimeList();

	for (int i = 0; i < P; i++) {
		tmp1 = to_string(primesList[i]); count = 0;
		for (int k = 0; k < tmp1.length(); k++) {
			for (int l = k + 1; l < tmp1.length(); l++) {
				for (int m = l + 1; m < tmp1.length(); m++) {
					count = 0; tmp2 = tmp1;
					for (int n = 0; n < 10; n++) {
						if ((k == 0 || l == 0 || m==0) && n == 0) continue;
						tmp2[k] = n + '0';
						tmp2[l] = n + '0';
						tmp2[m] = n + '0';
						if (isPrime(stoi(tmp2))) {
							count++;
						}

					}
					if (count == 8) {
						cout << primesList[i] << endl;
						count = 0;
						system("pause");
					}
				}
			}
		}
	}
	cout << "not found" << endl;
	system("pause");
	return 0;
}