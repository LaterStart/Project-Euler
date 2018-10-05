/*
Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; that is, a ratio of 8/13 ? 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. If this process is continued, what is the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%?
*/
// Completed on Fri, 20 Oct 2017
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
	int y = 1;
	int x;
	int split = 1 + 8 * y;
	int dif = 1;
	int difCount = 0;
	int primeCount = 0;
	int diagonalCount = 1;
	int sideLength = 1;
	double percent;

	for (int i = 2;;i++) {
		if (difCount == dif) {
			diagonalCount++;
			difCount = 0;
			difCount--;
			if (isPrime(i)) {
				primeCount++;
			}
		}
		if (i == split) {	
			sideLength += 2;
			y++;
			split += 8 * y;
			dif += 2;
			percent = ((double)primeCount / diagonalCount)*100;
			if (percent < 10) {
				cout << sideLength << endl;
				break;
			}	
		}
		difCount++;
	}
	system("pause");
	return 0;
}