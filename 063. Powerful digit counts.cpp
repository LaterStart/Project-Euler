/*
The 5-digit number, 16807=75, is also a fifth power. Similarly, the 9-digit number, 134217728=89, is a ninth power.

How many n-digit positive integers exist which are also an nth power?
*/
// Completed on Sun, 22 Oct 2017
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
	int**tmp = new int*[n2[0]+1];
	for (int i = 0; i <= n2[0]; i++) {
		tmp[i] = new int[n1[0] + n2[0]+1];
		for (int j = 0; j < n1[0] + n2[0]+1; j++) {
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
			x += n1[i]*n2[j];
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
	int count = 0;
	for (int i = 1;;i++) {
		number = storeNum(i);
		multiplied = number;
		for (int j = 2; ;j++) {
			multiplied = multiply(number, multiplied);
			if (multiplied[0] == j) {
				count++;
				cout << i << " " << j << endl;
				for (int k = 1; k <= multiplied[0]; k++) {
					cout << multiplied[k];
				}
				cout <<endl<<count+9<< endl;
			}
			if (j > multiplied[0]) {
				break;
			}
		}	
	}
	system("pause");
	return 0;
}