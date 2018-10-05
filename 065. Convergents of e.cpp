// Completed on Fri, 29 Dec 2017
#include <iostream>
using namespace std;

const unsigned int limit = 100;
int * elements = new int[limit];

int*num1 = nullptr;
int*num2 = nullptr;
int*den1 = nullptr;
int*den2 = nullptr;
int*tmp1 = nullptr;
int*tmp2 = nullptr;
int*tmp3 = nullptr;

void GenerateContinuedFractionSequence() {
	elements[0] = 2; elements[1] = 1;
	int pattern = 2, mem = 2, c = 0;
	for (int i = 2; i < limit; i++) {
		elements[i] = pattern;
		if (pattern > 1) {
			pattern = 1;
		}
		else if (pattern == 1) {
			c++;
			if (c == 2) {
				pattern = mem + 2;
				c = 0;
				mem = pattern;
			}
		}
	}
}

void StoreNumber(int n, int* &number) {
	number = new int[n + 1]; int pos = 1;
	do {
		number[pos++] = n % 10;	n /= 10;
	} while (n>0);
	number[0] = --pos;
}

void AddNumbers(int* n1, int* n2, int* &number) {
	number = new int[n1[0] + n2[0]];
	int n, x, z;
	n = (n1[0] > n2[0]) ? n1[0] : n2[0];
	z = 1, x = 0;
	for (int i = 1; i <= n; i++) {
		if (i > n1[0]) n1[i] = 0;
		if (i > n2[0]) n2[i] = 0;
		x += n1[i] + n2[i];
		if (x < 10) { number[z] = x; z++; x = 0; }
		else { number[z] = x % 10; x /= 10; z++; }
	}
	if (x > 0) {
		do {
			if (x < 10) { number[z] = x; z++; break; }
			else { number[z] = x % 10; x /= 10; z++; }
		} while (true);
	}
	number[0] = z - 1;
}

void Multiply(int *n1, int *n2, int* &number) {
	if (n1[0] > n2[0]) {
		int*tmp;
		tmp = n2;
		n2 = n1;
		n1 = tmp;
	}
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

	number = new int[n1[0] + n2[0]]; z = 1;
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
			if (x < 10) { number[z] = x; x = 0; z++; break; }
			else { number[z] = x % 10; x /= 10; z++; }
		} while (true);
	}
	number[0] = z - 1;
	for (int i = 0; i < n2[0] + 1; i++) {
		delete[]tmp[i];
	}
	delete[]tmp;
}

void Convergents(int element) {
	StoreNumber(element, tmp1);
	StoreNumber(1, tmp2);

	Multiply(num1, den2, tmp3);
	//delete[]num1;
	num1 = tmp3;
	tmp3 = nullptr;

	Multiply(num2, den1, tmp3);
	//delete[]den1;
	den1 = tmp3;
	tmp3 = nullptr;

	//delete[]num2;
	StoreNumber(1, num2);
	//delete[]den2;
	StoreNumber(1, den2);

	Multiply(tmp1, den1, tmp3);
	//delete[]tmp1;
	tmp1 = tmp3;
	tmp3 = nullptr;

	AddNumbers(tmp1, num1, tmp3);
	//delete[]num1;
	num1 = tmp3;
	tmp3 = nullptr;
}

int main() {
	GenerateContinuedFractionSequence();
	StoreNumber(1, num1);
	StoreNumber(1, num2);
	StoreNumber(elements[limit - 1], den1);
	StoreNumber(1, den2);

	for (int i = limit - 2; i >= 0; i--) {
		Convergents(elements[i]);
		//delete[]den2;
		den2 = den1;

		den1 = num1;
		num1 = nullptr;

		StoreNumber(1, num1);
	}
	num1 = den1;
	int sum = 0;
	for (int i = num1[0]; i > 0; i--) {
		sum += num1[i];
		cout << num1[i];
	}
	cout << endl;
	cout << sum << endl;
	system("pause");
	return 0;
}