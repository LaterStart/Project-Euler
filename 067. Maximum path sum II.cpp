/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)
*/
// Completed on Mon, 11 Sep 2017
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	ifstream read;
	read.open("triangle.txt");

	int lineCount = 0;
	int itemCount = 0;
	int ** polje=NULL;
	int ** poljeTmp=NULL;
	int * countArray=NULL;
	int * countArrayTmp=NULL;

	if (read.is_open()) {
		string line;
		string number;

		while (getline(read, line)) {
			lineCount++;
			stringstream row(line);
			poljeTmp = new int*[lineCount];
			countArrayTmp = new int[lineCount];

			if (lineCount == 1) {
				polje = new int*[1];
				countArray = new int[1];
			}

			while (row >> number) {
				itemCount++;

				poljeTmp[lineCount - 1] = new int[itemCount];
				poljeTmp[lineCount - 1][itemCount - 1] = stoi(number);

				for (int i = 0; i < itemCount - 1; i++) {
					poljeTmp[lineCount - 1][i] = polje[lineCount - 1][i];
				}

				if (itemCount != 1) {
					delete[]polje[lineCount - 1];
				}

				polje[lineCount - 1] = new int[itemCount];

				for (int i = 0; i < itemCount; i++) {
					polje[lineCount - 1][i] = poljeTmp[lineCount - 1][i];
				}
				delete[]poljeTmp[lineCount - 1];
			}
			countArrayTmp[lineCount - 1] = itemCount;
			delete[]poljeTmp;

			for (int i = 0; i < lineCount - 1; i++) {
				countArrayTmp[i] = countArray[i];
			}
			delete[]countArray;
			countArray = new int[lineCount];
			for (int i = 0; i < lineCount; i++) {
				countArray[i] = countArrayTmp[i];
			}
			delete[]countArrayTmp;

			poljeTmp = new int*[lineCount];
			for (int i = 0; i < lineCount; i++) {
				poljeTmp[i] = new int[countArray[i]];
				for (int j = 0; j < countArray[i]; j++) {
					poljeTmp[i][j] = polje[i][j];
				}
			}
			for (int i = 0; i < lineCount; i++) {
				delete[]polje[i];
			}
			delete[]polje;
			polje = new int *[lineCount + 1];

			for (int i = 0; i < lineCount; i++) {
				polje[i] = new int[countArray[i]];
				for (int j = 0; j < countArray[i]; j++) {
					polje[i][j] = poljeTmp[i][j];
				}
			}
			for (int i = 0; i < lineCount; i++) {
				delete[]poljeTmp[i];
			}
			delete[]poljeTmp;
			itemCount = 0;
		}
	}
	read.close();

	int newValue;

	for (int i = lineCount - 1; i > 0; i--) {
		for (int j = 0; j < countArray[i] - 1; j++) {
			if (polje[i - 1][j] + polje[i][j] > polje[i - 1][j] + polje[i][j + 1]) {
				newValue = polje[i - 1][j] + polje[i][j];
			}
			else {
				newValue = polje[i - 1][j] + polje[i][j + 1];
			}
			polje[i - 1][j] = newValue;
		}
	}
	cout << polje[0][0] << endl;

	system("pause");
	return 0;
}