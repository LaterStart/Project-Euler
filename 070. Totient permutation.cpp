/*
Euler's Totient function, ?(n) [sometimes called the phi function], is used to determine the number of positive numbers less than or equal to n which are relatively prime to n. 
For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and relatively prime to nine, ?(9)=6.
The number 1 is considered to be relatively prime to every positive number, so ?(1)=1.

Interestingly, ?(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

Find the value of n, 1 < n < 107, for which ?(n) is a permutation of n and the ratio n/?(n) produces a minimum.
*/
// Completed on Sun, 10 Dec 2017
#include <iostream>
#include <string>
using namespace std;

const unsigned int limit = 10000000;
bool *primeCheck = new bool[limit]();
unsigned int primesList[limit/10];
unsigned int *totient = new unsigned int[limit]();

void sieve() {
	double root = sqrt(limit);	
	for (unsigned int n = 4; n <= limit; n += 2) {
		primeCheck[n] = true;
	}
	for (unsigned int n = 3; n <= root; n += 2) {
		if (!primeCheck[n]) {
			for (unsigned int m = n*n; m <= limit; m += (2 * n)) {
				primeCheck[m] = true;
			}
		}
	}
	unsigned int count = 0;
	for (unsigned int i = 2; i < limit; i++) {
		if (!primeCheck[i]) {
			primesList[++count] = i;			
		}
	}
	primesList[0] = count;
}

void totientPrimePowers() {
	unsigned int n = primesList[0];
	unsigned long long int x;
	unsigned int y;
	for (unsigned int i = 1; i <= n; i++) {
		y = primesList[i];
		for (unsigned int j = 1; ; j++) {
			x = pow(y, j);			
			if (x > limit) break;
			totient[x] = x - pow(y, j - 1);
		}	
	}
}

void totientSemiPrimes() {
	unsigned int n = primesList[0];
	unsigned long long x;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			x = primesList[i]*primesList[j];
			if (x >= limit)break;
			totient[x] = (primesList[i] - 1)*(primesList[j] - 1);			
		}
	}
}

int main() {
	sieve();
	totient[1] = 1;
	totientPrimePowers();
	totientSemiPrimes();	

	string tmp1, tmp2;
	char tmp;
	int sum1, sum2;
	int product1, product2;
	double ratio;
	double min = 9999;
	int mem;
	for (unsigned int i = 2; i < limit; i++) {		
		if (totient[i] != NULL) {
			tmp1 = to_string(i);
			tmp2 = to_string(totient[i]);
			if (tmp1.length() == tmp2.length()) {
				sum1 = 0; sum2 = 0; product1 = 1; product2 = 1;
				for (int j = 0; j < tmp1.length(); j++) {
					sum1 += tmp1[j] - '0';
					sum2 += tmp2[j] - '0';
					product1 *= tmp1[j];
					product2 *= tmp2[j];
				}
				if (sum1 == sum2 && product1 == product2) {
					ratio = static_cast<double>(i) / static_cast<double>(totient[i]);
					if (ratio < min) {
						min = ratio;
						mem = i;
					}
				}
			}
		}
	}
	cout << mem << endl;
	system("pause");
	return 0;
}