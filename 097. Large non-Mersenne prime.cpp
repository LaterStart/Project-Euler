/*The first known prime found to exceed one million digits was discovered in 1999, and is a Mersenne prime of the form 26972593−1; it contains exactly 2,098,960 digits.
Subsequently other Mersenne primes, of the form 2p−1, have been found which contain more digits.
However, in 2004 there was found a massive non-Mersenne prime which contains 2,357,207 digits: 28433×27830457+1.
Find the last ten digits of this prime number.*/
// Completed on Thu, 26 Oct 2017
#include <iostream>
using namespace std;

int* storeNum(int n) {
	int z = 1;
	int*tmp;
	int*number = new int[z];
	number[0] = NULL;
	do {
		tmp = new int[z + 1];
		for (int i = 0; i < z; i++)
			tmp[i] = number[i];
		if (n < 10) {
			tmp[z] = n; z++;
			delete[]number;
			number = new int[z];
			for (int i = 0; i < z; i++)
				number[i] = tmp[i];
			delete[]tmp; break;
		}
		else {
			tmp[z] = n % 10;	n /= 10; z++;
			delete[]number;
			number = new int[z];
			for (int i = 0; i < z; i++)
				number[i] = tmp[i];
			delete[]tmp;
		}
	} while (true);
	number[0] = z - 1; return number;
}
int* multiply(int *n1, int *n2) {
	int x = 0, r = 1, z;
	int**tmp = new int*[n2[0] + 1];
	for (int i = 0; i <= n2[0]; i++) {
		tmp[i] = new int[n1[0] + n2[0] + 1];
		for (int j = 0; j < n1[0] + n2[0] + 1; j++) {
			tmp[i][j] = NULL;
		}
	}
	for (int i = 1; i <= n1[0]; i++) {
		z = 1;
		for (int k = 1; k < r; k++) {
			tmp[r][z] = 0;
			z++;
		}
		for (int j = 1; j <= n2[0]; j++) {
			x += n1[i] * n2[j];
			if (x < 10) { tmp[r][z] = x;	z++; x = 0; }
			else { tmp[r][z] = x % 10; x /= 10; z++; }
		}
		if (x > 0) {
			do {
				if (x < 10) { tmp[r][z] = x;	x = 0; z++; break; }
				else { tmp[r][z] = x % 10; x /= 10; z++; }
			} while (true);
		}tmp[r][0] = z - 1; r++;
	}tmp[0][0] = r - 1;

	int*number = new int[n1[0] + n2[0]]; z = 1;
	for (int i = 1; i <= tmp[tmp[0][0]][0]; i++) {
		for (int j = 1; j <= tmp[0][0]; j++) {
			x += tmp[j][i];
		}
		if (x < 10) {
			number[z] = x; z++; x = 0;
		}
		else {
			number[z] = x % 10; x /= 10; z++;
		}
	}
	if (x > 0) {
		do {
			if (x < 10) { number[z] = x; x = 0; break; }
			else { number[z] = x % 10; x /= 10; z++; }
		} while (true);
	}
	number[0] = z - 1;
	for (int i = 0; i < n2[0] + 1; i++) {
		delete[]tmp[i];
	}
	delete[]tmp;
	return number;
}
int main() {
	int n = 0;
	int*number;
	int*multiplied;
	number = storeNum(2);
	multiplied = number;
	for (int j = 0; j<7830457-1; j++) {
		multiplied = multiply(number, multiplied);
		if (multiplied[0] > 10) {	
			multiplied[0] = 10;
		}
	}	
	multiplied = multiply(storeNum(28433), multiplied);
	for (int i = 10; i >=1; i--) {
		cout << multiplied[i];
	}

	system("pause");
	return 0;
}