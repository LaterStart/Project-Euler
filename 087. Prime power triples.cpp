// Completed on Fri, 5 Jan 2018
#include <iostream>
using namespace std;

const unsigned int limit = 1000000;
unsigned int primesList[limit + 1];
bool *primeCheck = new bool[limit + 1]();

void sieve() {
	double root = sqrt(limit);
	for (unsigned long long n = 4; n <= limit; n += 2) {
		primeCheck[n] = true;
	}
	for (unsigned long long n = 3; n <= root; n += 2) {
		if (!primeCheck[n]) {
			for (unsigned long long m = n * n; m <= limit; m += (2 * n)) {
				primeCheck[m] = true;
			}
		}
	}
	unsigned long long count = 0;
	for (unsigned long long i = 2; i <= limit; i++) {
		if (!primeCheck[i]) {
			primesList[++count] = i;
		}
	}
	primesList[0] = count;
}

int main() {
	sieve();

	int square, cube, fourth;
	int result = 0;
	bool * results = new bool[limit]();
	for (int a = 1; a <= primesList[0]; a++) {
		square = primesList[a] * primesList[a];
		if (square >= limit) break;
		for (int b = 1; b <= primesList[0]; b++) {
			cube = primesList[b] * primesList[b] * primesList[b];
			if (square + cube >= limit)break;
			for (int c = 1; c <= primesList[0]; c++) {
				fourth = primesList[c] * primesList[c] * primesList[c] * primesList[c];
				if ((square + cube + fourth) >= limit) break;
				results[square + cube + fourth] = 1;
			}
		}
	}
	for (int i = 0; i < limit; i++) {
		if (results[i])result++;
	}
	cout << result << endl;
	system("pause");
	return 0;
}