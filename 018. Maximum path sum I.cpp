/*By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

	3
   7 4
  2 4 6
 8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

			  75
			 95 64
		    17 47 82
		   18 35 87 10
		  20 04 82 47 65
		 19 01 23 75 03 34
	    88 02 77 73 07 63 67
       99 65 04 28 06 16 70 92
	  41 41 26 56 83 40 80 70 33
     41 48 72 33 47 32 37 16 94 29
    53 71 44 65 25 43 91 52 97 51 14
   70 11 33 28 77 73 17 78 39 68 17 57
  91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23*/
// Completed on Mon, 11 Sep 2017
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	ifstream read;
	read.open("file.txt");

	int lineCount = 0;
	int itemCount = 0;
	int ** polje;
	int ** poljeTmp;
	int * countArray;
	int * countArrayTmp;

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

	for (int i = lineCount-1; i > 0; i--) {
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