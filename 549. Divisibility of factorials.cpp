/*
The smallest number m such that 10 divides m! is m=5.
The smallest number m such that 25 divides m! is m=10.

Let s(n) be the smallest number m such that n divides m!.
So s(10)=5 and s(25)=10.
Let S(n) be ∑s(i) for 2 ≤ i ≤ n.
S(100)=2012.

Find S(108).
*/
// Completed on Fri, 24 Nov 2017 - DOES NOT APPLY 1 MINUTE RULE , NEEDS TO BE IMPROVED.
#include <iostream>
using namespace std;

unsigned int N = pow(10,8); int P = 0;
unsigned long long sum = 0;
int * table = new int[N+1]();
int * primesList = new int[N + 1](); 
int * semiPrimesTable = new int[N + 1]();
int * primedNumbersTable = new int[N + 1]();
int ** primePowersTable = new int*[N + 1]();


void generatePrimelist() {
	bool prime;
	for (unsigned long n = 31; n <= N; n += 2) {	
		if (n % 2 != 0 && n % 3 != 0 && n % 5 != 0 && n % 7 != 0 && n% 11!=0 && n%13!=0 && n%17!=0 && n%19!=0 && n%23!=0 && n%29!=0 && n%31!=0 && n%37!=0) {
			prime = true;
			for (int j = 11; primesList[j] <= sqrt(n); j++) {
				if (n%primesList[j] == 0) {
					prime = false;
					break;
				}
			}
			if (prime) {	
				primesList[P] = n; P++;
				table[n] = n; sum += n;
			}
		}
	}
}

void primedOnlyNumbers() {
	int a, b, c, d, e, f, g;
	for (int i = 0; i < P; i++) {
		for (int j= i+1; j < P; j++) {
			a = primesList[i] * primesList[j];			
			if (a > N)break;
			if (a <= N) { table[a] = primesList[j]; sum += primesList[j]; }
			for (int k = j+1; k < P; k++) {
				b = primesList[i] * primesList[j] * primesList[k];				
				if (b > N)break;
				if (b <= N) { table[b] = primesList[k]; sum += primesList[k]; }
				for (int l = k+1; l < P; l++) {
					c = primesList[i] * primesList[j] * primesList[k] * primesList[l];					
					if (c > N)break;
					if (c <= N) { table[c] = primesList[l]; sum += primesList[l]; }
					for (int m = l+1; m < P; m++) {
						d = primesList[i] * primesList[j] * primesList[k] * primesList[l] * primesList[m];						
						if (d > N)break;
						if (d <= N) { table[d] = primesList[m]; sum += primesList[m]; }
						for (int n = m+1; n < P; n++) {
							e = primesList[i] * primesList[j] * primesList[k] * primesList[l] * primesList[m] * primesList[n];							
							if (e > N) break;
							if (e <= N) { table[e] = primesList[n]; sum += primesList[n]; }
							for (int o=n+1 ; o < P; o++) {
								f = primesList[i] * primesList[j] * primesList[k] * primesList[l] * primesList[m] * primesList[n] * primesList[o];								
								if (f > N) break;
								if (f <= N) { table[f] = primesList[o]; sum += primesList[o]; }
								for (int r =o+1; r < P; r++) {
									g = primesList[i] * primesList[j] * primesList[k] * primesList[l] * primesList[m] * primesList[n] * primesList[o] * primesList[r];
									if (g > N) break;
									if (g <= N) { table[g] = primesList[r]; sum += primesList[r]; }
								}
							}
						}					
					}
				}
			}
		}
	}
}

int composite(int n) {
	unsigned int max = 0;
	unsigned int p;
	for (unsigned int i = 0; i < P; i++) {
		if (n % primesList[i] == 0) {
			p = 1;
			while (n % primesList[i] == 0) {
				n /= primesList[i];
				p *= primesList[i];
			}
			max = (table[p] > max) ? table[p] : max;
		}
		if (n == 1) return max;
	}
}

// Legendre's Theorem 
int*** factorialFactorsTable = new int**[N + 1]();
int** factorialFactors(int n) {
	if (factorialFactorsTable[n] != NULL) return factorialFactorsTable[n];

	factorialFactorsTable[n] = new int*[n / 2 + 2];
	for (int i = 0; i < n / 2 + 2; i++) {
		factorialFactorsTable[n][i] = new int[2]();
	}
	int z = 1;
	for (int i = 0; primesList[i] <= n; i++) {		
		factorialFactorsTable[n][z][0] = primesList[i]; z++;		
	}
	factorialFactorsTable[n][0][0] = z - 1; int count;
	for (int i = 1; i <= factorialFactorsTable[n][0][0]; i++) {
		for (int j = 1; ; j++) {
			if (factorialFactorsTable[n][i][0] * j > n) {
				break;
			}
			else if ((factorialFactorsTable[n][i][0] * j) % factorialFactorsTable[n][i][0] == 0) {
				factorialFactorsTable[n][i][1]++;
			}
		}
		count = 0;
		for (int j = 1; j <= factorialFactorsTable[n][i][1]; j++) {
			if (j%factorialFactorsTable[n][i][0] == 0) {
				count++;
			}
		}
		factorialFactorsTable[n][i][1] += count; int tmp = 0;
		do {
			for (int j = 1; j <= count; j++) {
				if (j%factorialFactorsTable[n][i][0] == 0) {
					tmp++;
				}
			}
			factorialFactorsTable[n][i][1] += tmp;
			if (tmp <= 1) {
				break;
			}
			count = tmp;
			tmp = 0;
		} while (true);
	}
	return factorialFactorsTable[n];
}

int main() {
	int **_factors, ** __factors;
	int n, max;
	unsigned long long x;

	//initialize prime lists and tables
	primesList[0] = 2; primesList[1] = 3; primesList[2] = 5;
	primesList[3] = 7; primesList[4] = 11; primesList[5] = 13;
	primesList[6] = 17; primesList[7] = 19; primesList[8] = 23;
	primesList[9] = 29; primesList[10] = 31; primesList[11] = 37;
	table[2] = 2; table[3] = 3; table[5] = 5; table[7] = 7; table[11] = 11;
	table[13] = 13; table[17] = 17; table[19] = 19; table[23] = 23; table[29] = 29; table[31] = 31;
	table[37] = 37;	P = 12; sum += 197;
	generatePrimelist();
	
	//create prime powers table
	x = 0;
	for (int i = 0; i < P; i++) {
		n = primesList[i];
		for (int j = 1; ; j++) {
			x = pow(n, j);
			if (x <= N) {
				primePowersTable[x] = new int[2];
				primePowersTable[x][0] = n;
				primePowersTable[x][1] = j;
			}
			else break;
		}
	}	

	//create semi-primes and multiprimes only table
	//primedOnlyNumbers();
	cout << "start" << endl;
	//loop trough divisors
	for (unsigned int i = 2; i <= N; i++) {
		if (table[i] != NULL) {
			//cout << i << " " << table[i] << endl;
			continue;
		}
		else {			
			//if n is power of prime (n=p^y)
			if (primePowersTable[i] != nullptr) {
				for (int p = 1;; p++) {
					__factors = factorialFactors(primePowersTable[i][0] * p);
					for (int j = 1; j <= __factors[0][0]; j++) {
						if (__factors[j][0] == primePowersTable[i][0]) {
							n = __factors[j][1];
							break;
						}
					}
					if (n >= primePowersTable[i][1]) {						
						cout << i << " " << primePowersTable[i][0] * p << endl;
						sum += primePowersTable[i][0] * p;
						table[i] = primePowersTable[i][0] * p;
						break;
					}
				}
				continue;
			}
			else {
				table[i] = composite(i);
				//cout << i << " " << table[i] << endl;
				sum += table[i];
			}
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}