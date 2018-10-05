//projecteuler.net/problem=69
// Completed on Thu, 26 Oct 2017
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
int* factorization(int n) {
	int * factors = new int[n / 2+1];
	int z = 1, i = 2;
	bool skip;
	do {
		skip = false;
		if (isPrime(i)) {
			if (n%i == 0) {
				for (int j = 1; j < z; j++) {
					if (i == factors[j]) {
						n /= i;
						skip = true;
						break;
					}
				}
				if (skip) {
					continue;
				}
				factors[z] = i;
				n /= i;
				z++;
			}
			else {
				if (isPrime(n)) {
					factors[z] = n;
					z++;
					break;
				}
				i++;
			}
		}
		else {
			i++;
		}
	} while (n>1);
	factors[0] = z - 1;
	return factors;
}
int main() {
	int * factors;
	double phi, nPhi;
	double max = 0.0;
	int nMax=0;
	for (int i = 2; i <= 1000000; i++) {
		if (isPrime(i)) {
			phi = i - 1;
			nPhi = static_cast<double>(i) / phi;
			if (nPhi > max) {
				max = nPhi;
			}
			continue;
		}
		factors = factorization(i);
		phi = 1.0;
		for (int j = 1; j <= factors[0]; j++) {
			phi *= (1 - (1.0 / factors[j]));
		}
		phi *= i;
		nPhi = static_cast<double>(i) / phi;
		if (nPhi > max) {
			max = nPhi;
			nMax = i;
		}
		delete[]factors;
	}
	cout << nMax <<" "<<max << endl;
	system("pause");
	return 0;
}