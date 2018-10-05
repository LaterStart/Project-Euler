/*
It is possible to show that the square root of two can be expressed as an infinite continued fraction.

? 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...

By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?

numerator+2*denominator/numerator+denominator
*/
// Completed on Sun, 15 Oct 2017
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double parseString(string f) {
string strs[10000];
	int z = 0, i = 0;
	do {
		if (f[i] == '1' || f[i] == '2') {	
			strs[z] += f[i];
		}
		else if (f[i] == '/' || f[i] == '+') {	
			strs[z] += f[i];
		}
		else if (f[i] == '(') {
			z++;
		}
		else if (f[i] == ')') {
			break;
		}
		else {
			cout << "error" << endl;
			break;
		}
		i++;
	} while (true);
	double x;
	for (int i = z; i >= 0; i--) {
		if(strs[i].length()==5){
			x = static_cast<double>(strs[i][2] - '0') / static_cast<double>(strs[i][4] - '0');
			x += static_cast<double>(strs[i][0] - '0');
			continue;
		}
		if (strs[i].length() == 4) {
			x = static_cast<double>(strs[i][2] - '0') / x + static_cast<double>(strs[i][0] - '0');
			continue;
		}
	}
	return x;
}
int main() {
	//numerator+2*denominator/numerator+denominator
	int num = 3, den=2;
	int count = 0, x = 0, z, itr;
	int***fld = new int**[1000];
	for (int i = 0; i < 1000; i++) {
		fld[i] = new int*[2];
		for (int j = 0; j < 2;j++) {
			fld[i][j] = new int[1000];
			for (int k = 0; k < 1000; k++) {
				fld[i][j][k] = NULL;
			}
		}
	}
	fld[0][0][0] = 1; fld[0][1][0] = 1;
	fld[0][0][1] = 3; fld[0][1][1] = 2;

	int tmp[1000];
	for (int i = 1; i < 1000; i++) {
		for (int d = 0; d < 1000; d++) {
			tmp[d] = NULL;
		}
		z = 1;
		for (int j = 1; j <= fld[i - 1][1][0]; j++) {
			x += 2 * fld[i - 1][1][j];
			if (x < 10) { tmp[z] = x; x = 0; z++; }
			else { tmp[z] = x % 10; x /= 10; z++; }
		}
		if (x > 0) {
			do {
				if (x < 10) { tmp[z] = x; x = 0; z++; break; }
				else { tmp[z] = x % 10; x /= 10; z++; }
			} while (true);
		}
		tmp[0] = z - 1; z = 1;
		if (fld[i - 1][0][0] > tmp[0]) {
			itr = fld[i - 1][0][0];	}
		else { itr = tmp[0]; }
		for (int k = 1; k <= itr; k++) {
			x += fld[i - 1][0][k] + tmp[k];
			if (x < 10) { fld[i][0][z] = x; x = 0; z++; }
			else { fld[i][0][z] = x % 10; x /= 10; z++; }
		}
		if (x > 0) {
			do {
				if (x < 10) { fld[i][0][z] = x; x = 0; z++; break; }
				else { fld[i][0][z] = x % 10; x /= 10; z++; }
			} while (true);
		}
		fld[i][0][0] = z - 1; z = 1;
		if (fld[i - 1][0][0] > fld[i-1][1][0]) {
			itr = fld[i - 1][0][0];
		}
		else { itr = fld[i - 1][1][0]; }
		for (int m = 1; m <= itr; m++) {
			x += fld[i - 1][0][m] + fld[i - 1][1][m];
			if (x < 10) { fld[i][1][z] = x; x = 0; z++; }
			else { fld[i][1][m] = x % 10; x /= 10; z++; }
		}
		if (x > 0) {
			do {
				if (x < 10) { fld[i][1][z] = x; x = 0; z++; break; }
				else { fld[i][1][z] = x % 10; x /= 10; z++; }
			} while (true);
		}
		fld[i][1][0] = z - 1;
	}
	for (int i = 0; i < 1000; i++) {
		if (fld[i][0][0] > fld[i][1][0]) {
			count++;
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}