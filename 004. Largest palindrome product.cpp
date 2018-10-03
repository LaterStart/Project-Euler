// A palindromic number reads the same both ways.The largest palindrome made from the product of two 2 - digit numbers is 9009 = 91 × 99.
// Find the largest palindrome made from the product of two 3 - digit numbers.
// Completed on Mon, 31 Jul 2017
#include <iostream>
using namespace std;


int main() {
	int max;
	int x;
	int digit = 3;
	int div;
	int num = digit * 2;
	int n = 0;
	int xy = 0;
	int a, b = 0;
	int v, d;
	bool check;
	int f;
	int e = 0;
	int h = 1;
	int num1, number = 0;

	div = pow(10, digit);
	max = div - 1;

	int *** polje1 = new int**[max];
	int *** polje2 = new int**[max];
	int ** polje3 = new int*[max*max];

	for (int i = 1; i <= max; i++) {
		polje1[i] = new int*[max];
		polje2[i] = new int*[max];
		for (int j = 1; j <= max; j++) {
			x = i*j;
			xy = x;
			n = 0;
			do {
				xy = xy / 10;
				n++;
			} while (xy != 0);
			polje1[i][j] = new int[n];
			polje2[i][j] = new int[n];
			v = 1;
			for (int z = 0; z < n; z++) {
				a = x / v % 10;
				polje1[i][j][z] = a;
				v = v * 10;
			}
			v = v / 10;
			for (int q = 0; q < n; q++) {
				b = x / v % 10;
				polje2[i][j][q] = b;
				v = v / 10;
			}
			d = n;
			check = false;
			f = 0;
			for (int c = 0; c < n; c++) {
				if (polje1[i][j][c] == polje2[i][j][c]) {
					check = true;
				}
				else {
					check = false;
					f++;
				}
			}
			if (check == true && f == 0) {
				polje3[e] = new int[n];
				for (int c = 0; c < n; c++) {
					polje3[e][c] = polje1[i][j][c] * h;
					h = h * 10;
				}
				h = 1;
				num1 = 0;
				for (int c = 0; c < n; c++) {
					num1 += polje3[e][c];
				}

				if (number < num1) {
					number = num1;
				}
				e++;
			}
		}
	}

	cout << number << endl;

	system("pause");
	return 0;
}