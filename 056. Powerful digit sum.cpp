/*
A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.

Considering natural numbers of the form, ab, where a, b < 100, what is the maximum digital sum?
*/
// Completed on Sun, 15 Oct 2017
#include <iostream>
using namespace std;

int main() {
	int ** num = new int*[100];
	int * numTmp;
	for (int i = 0; i < 100; i++) {
		num[i] = new int[500];
	}

	int x, y;
	for (int i = 1; i <= 100; i++) {
		x = i; y = 2;
		do {
			if (x < 10) {
				num[i - 1][y] = x;
				y++;
				break;
			}
			else {
				num[i - 1][y] = x % 10;
				x /= 10;
				y++;
			}
		} while (true);
		num[i - 1][0] = i;
		num[i - 1][1] = y - 2;
	}

	int**tmp;
	int r, s;
	int sum;
	int max = 0;
	for (int numberIndex = 0; numberIndex < 100; numberIndex++) {
		numTmp = new int[500];
		for (int n = 0; n <= num[numberIndex][1]; n++) {
			numTmp[n] = num[numberIndex][n + 1];
		}
		tmp = new int*[num[numberIndex][1]];
		for (int zero = 0; zero < num[numberIndex][1]; zero++) {
			tmp[zero] = new int[500];
			for (int v = 0; v < 500; v++) {
				tmp[zero][v] = 0;
			}
		}
		for (int exp = 1; exp <= 100; exp++) {			
			r = 0, x = 0;
			for (int k = 2; k <= num[numberIndex][1] + 1; k++) {
				s = 1;
				for (int b = 0; b < r; b++) {
					tmp[r][s] = 0;
					s++;
				}
				for (int m = 1; m <= numTmp[0]; m++) {
					x += num[numberIndex][k] * numTmp[m];
					if (x < 10) {
						tmp[r][s] = x;
						x = 0;
						s++;
					}
					else {
						tmp[r][s] = x % 10;
						x /= 10;
						s++;
					}
				}
				if (x > 0) {
					do {
						if (x < 10) {
							tmp[r][s] = x;
							x = 0;
							s++;
							break;
						}
						else {
							tmp[r][s] = x % 10;
							x /= 10;
							s++;
						}
					} while (true);

				}
				tmp[r][0] = s - 1;
				r++;
			}
			s = 1, x = 0;
			for (int a = 1; a <= tmp[r - 1][0]; a++) {
				for (int b = 0; b < r; b++) {
					x += tmp[b][a];
				}
				if (x < 10) {
					numTmp[s] = x;
					x = 0;
					s++;
				}
				else {
					numTmp[s] = x % 10;
					x /= 10;
					s++;
				}
			}
			if (x > 0) {
				do {
					if (x < 10) {
						numTmp[s] = x;
						s++;
						break;
					}
					else {
						numTmp[s] = x % 10;
						x /= 10;
						s++;
					}
				} while (true);
			}
			numTmp[0] = s - 1;
			sum = 0;
			for (int i = 1; i <= numTmp[0]; i++) {
				//cout << numTmp[i];
				sum += numTmp[i];
			}
			cout << sum << endl;
			if (sum > max) {
				max = sum;
			}			
		}
		for (int v = 0; v < num[numberIndex][1]; v++) {
			delete[]tmp[v];
		}
		delete[]tmp;
		delete[]numTmp;
	}	
	cout << max << endl;
	system("pause");
	return 0;
}