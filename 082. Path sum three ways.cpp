//projecteuler.net/problem=82
// Completed on Mon, 26 Feb 2018
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

int main() {
	clock_t tStart = clock();
	const int siz = 80;
	fstream read;
	int matrix[siz][siz];
	read.open("matrix.txt");
	if (read.is_open()) {
		string tmp;		
		for (int i = 0; i < siz; i++) {
			for (int j = 0; j < siz; j++) {
				read >> tmp;
				matrix[i][j] = stoi(tmp);				
			}
		}
	}
	read.close();
	cout << endl << endl;
	
	int min, tmp;
	int abc[3];
	int tmpTable[siz];
	int tmpTable_[siz][2];
	
	for (int col = 1; col < siz; col++) {
		for (int row = 0; row < siz; row++) {
			if (row == 0) 
				tmpTable[row] = (matrix[row][col] + matrix[row][col - 1] < matrix[row][col] + matrix[row + 1][col] + matrix[row + 1][col - 1]) ? matrix[row][col] + matrix[row][col - 1] : matrix[row][col] + matrix[row + 1][col] + matrix[row + 1][col - 1];
			else if (row == siz - 1) 
				tmpTable[row] = (matrix[row][col] + matrix[row][col - 1] < matrix[row][col] + matrix[row - 1][col] + matrix[row - 1][col - 1]) ? matrix[row][col] + matrix[row][col - 1] : matrix[row][col] + matrix[row - 1][col] + matrix[row - 1][col - 1];
			else {
				abc[0] = matrix[row][col] + matrix[row][col - 1];
				abc[1] = matrix[row][col] + matrix[row + 1][col] + matrix[row + 1][col - 1];
				abc[2] = matrix[row][col] + matrix[row - 1][col] + matrix[row - 1][col - 1];

				tmp = abc[0];
				for (int k = 1; k < 3; k++)
					if (abc[k] < tmp)
						tmp = abc[k];
				tmpTable[row] = tmp;
			}
		}
		tmpTable_[0][0] = tmpTable[0];
		for (int i = 1; i < siz; i++) 
			tmpTable_[i][0] = (tmpTable[i] < matrix[i][col] + tmpTable_[i-1][0]) ? tmpTable[i] : matrix[i][col] + tmpTable_[i-1][0];
		tmpTable_[siz-1][1] = tmpTable[siz-1];
		for (int i = siz - 2; i >= 0; i--)
			tmpTable_[i][1] = (tmpTable[i] < matrix[i][col] + tmpTable_[i+1][1]) ? tmpTable[i] : matrix[i][col] + tmpTable_[i+1][1];

		for (int i = 0; i < siz; i++)
			matrix[i][col] = (tmpTable_[i][0] < tmpTable_[i][1]) ? tmpTable_[i][0] : tmpTable_[i][1];

	}
	min = matrix[0][siz - 1];
	for (int i = 1; i < siz; i++)
		if (matrix[i][siz - 1] < min)
			min = matrix[i][siz - 1];

	cout << endl<<min << endl;
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}