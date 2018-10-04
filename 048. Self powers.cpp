/*The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.*/
// Completed on Sat, 14 Oct 2017
#include <iostream>
using namespace std;

int main() {
	int ** num = new int*[1001];
	int ** tmp;
	int * numTmp;
	num[0] = new int[2];
	num[0][0] = 1;
	num[0][1] = 1;
	for (int i = 1, n = 2, x, y; i < 1000;) {
		num[i] = new int[n];
		numTmp = new int[n];
		i++; x = i; y = 1;
		do {
			if (x < 10) {
				num[i - 1][y] = x;
				numTmp[y] = x;
				break;
			}
			else {
				num[i - 1][y] = x % 10;
				numTmp[y] = x % 10;
				x /= 10;
				y++;
			}
		} while (true);
		num[i - 1][0] = y;
		numTmp[0] = y;
		tmp = new int*[y];
		for (int v = 0; v < y; v++) {
			tmp[v] = new int[n];
			for (int vv = 0; vv < n; vv++) {
				tmp[v][vv] = 0;
			}
		}
		int r, s;
		for (int j = 1; j < i; j++) {
			r = 0, x = 0;
			for (int k = 1; k <= num[i - 1][0]; k++) {
				s = 1;
				for (int b = 0; b < r; b++) {
					tmp[r][s] = 0;
					s++;
				}
				for (int m = 1; m <= numTmp[0]; m++) {
					x += num[i - 1][k] * numTmp[m];
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
		}
		x = 0, s = 1;
		int previous;
		for (int z = 1; z <= numTmp[0]; z++) {
			if (num[i - 2][z] < 0) {
				previous = 0;
			}
			else {
				previous = num[i - 2][z];
			}
			x += numTmp[z] + previous;
			if (x < 10) {
				num[i - 1][s] = x;
				x = 0;
				s++;
			}
			else {
				num[i - 1][s] = x % 10;
				x /= 10;
				s++;
			}
		}
		if (x > 0) {
			do {
				if (x < 10) {
					num[i - 1][s] = x;
					x = 0;
					s++;
					break;
				}
				else {
					num[i - 1][s] = x % 10;
					x /= 10;
					s++;
				}
			} while (true);
		}
		num[i - 1][0] = s-1;
		if (i == 1000) {
			for (int z = num[i - 1][0]; z > 0; z--) {
				cout << num[i - 1][z];
			}
		}
		for (int v = 0; v < y; v++) {
			delete[]tmp[v];
		}
		delete[]tmp;
		delete[]numTmp;		
		n += 10;
	}
	system("pause");
	return 0;
}