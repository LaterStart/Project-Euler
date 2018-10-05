/*It is possible to write five as a sum in exactly six different ways:

4 + 1
3 + 2
3 + 1 + 1
2 + 2 + 1
2 + 1 + 1 + 1
1 + 1 + 1 + 1 + 1

How many different ways can one hundred be written as a sum of at least two positive integers?*/
// Completed on Sun, 29 Oct 2017
#include <iostream>
using namespace std;

int main() {
	int matrix[100][101];
	for (int i = 0; i < 1; i++) {
		for (int j = 1; j <= 100; j++) {
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = 1;
	int x, y;
	for (int i = 1; i <= 99; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i == j) {
				x = 1 + matrix[i - 1][j];
				matrix[i][j] = x;
			}
			else if (i > j) {
				x = matrix[i - 1][j];
				matrix[i][j] = x;
			}
			else if (j > i) {
				y = j - i;
				x = matrix[i][y] + matrix[i - 1][j];
				matrix[i][j] = x;
			}			
		}
	}
	cout << matrix[99][100] << endl;
	system("pause");
	return 0;
}