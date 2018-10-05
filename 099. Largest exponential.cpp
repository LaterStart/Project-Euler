/*
Comparing two numbers written in index form like 211 and 37 is not difficult, as any calculator would confirm that 211 = 2048 < 37 = 2187.

However, confirming that 632382518061 > 519432525806 would be much more difficult, as both numbers contain over three million digits.

Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example given above.
*/
// Completed on Fri, 27 Oct 2017
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream read;
	read.open("base_exp.txt");
	double max = 0.0;
	double x;
	int line = 0;
	int lineMem;
	if (read.is_open()) {
		string tmp, tmp1;
		bool calculate = false;
		do {
			read >> tmp;
			if (calculate) {
				calculate = false;
				x = log(stoi(tmp1))*stoi(tmp);
				line++;
				if (x > max) {
					max = x;
					lineMem = line;
				}
				continue;					
			}
			tmp1 = tmp;
			calculate = true;
		} while (!read.eof());
	}
	read.close();
	cout << lineMem <<" "<< max << endl;

	system("pause");
	return 0;
}