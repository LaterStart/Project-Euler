// Completed on Fri, 29 Dec 2017
#include <iostream>
using namespace std;

bool pandigital;
bool isPandigital(int* number) {
	pandigital = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i != j) {
				if (number[i] == 0 || number[i] == number[j]) {
					pandigital = false;
					break;
				}
			}
		}
	}
	return pandigital;
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

int main() {
	int*num1 = nullptr; StoreNumber(1, num1);
	int*num2 = nullptr; StoreNumber(2, num2);
	int*num3 = nullptr; StoreNumber(0, num3);
	int k = 3; int n; int number[9];

	while (true) {
		k++;
		AddNumbers(num1, num2, num3);
		delete[]num1;
		num1 = num2;
		num2 = num3;
		num3 = nullptr;
		n = 0;
		for (int i = num2[0]; n < 9 && i>0; n++) {
			number[n] = num2[i--];
		}
		if (isPandigital(number)) {
			cout << k << endl;
			n = 0;
			for (int i = 1; n < 9 && i <= num2[0]; n++) {
				number[n] = num2[i++];
			}
			if (isPandigital(number)) {
				cout << k << endl;
				system("pause");
			}
		}
	}
	return 0;
}