/*In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right, by only moving to the right and down, is indicated in bold red and is equal to 2427.
projecteuler.net/problem=81
Find the minimal path sum, in matrix.txt (right click and "Save Link/Target As..."), a 31K text file containing a 80 by 80 matrix, from the top left to the bottom right by only moving right and down.*/
// Completed on Sat, 28 Oct 2017
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	fstream read;
	int matrix[80][80];
	read.open("matrix.txt");
	if (read.is_open()) {
		string tmp;
		cout << "Reading.." << endl;
		for (int i = 0; i < 80; i++) {
			for (int j = 0; j < 80; j++) {
				read >> tmp;
				matrix[i][j] = stoi(tmp);
			}
		}
	}
	read.close();
	int tmp1, tmp2;
	for (int i = 0; i < 79; i++) {
		matrix[0][i + 1] = matrix[0][i] + matrix[0][i + 1];
		matrix[i + 1][0] = matrix[i][0] + matrix[i + 1][0];
	}
	for (int i = 1; i < 80; i++) {
		for (int j = 1; j < 80; j++) {
			tmp1 = matrix[i][j] + matrix[i - 1][j];
			tmp2 = matrix[i][j] + matrix[i][j - 1];
			if (tmp1 < tmp2) { matrix[i][j] = tmp1; }
			else { matrix[i][j] = tmp2; }
		}
	}
	cout << matrix[79][79] << endl;
	system("pause");
	return 0;
}