/* 70 colored balls are placed in an urn, 10 for each of the seven rainbow colors.

What is the expected number of distinct colors in 20 randomly picked balls?

Give your answer with nine digits after the decimal point (a.bcdefghij). */
// Completed on Sun, 12 Nov 2017
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double probability = 1.0;
	double x;
	for (int i = 0; i < 20; i++) {
		x = (60.0 - i) / (70.0 - i);
		probability *= x;
	}
	cout <<setprecision(11)<< (1-probability)*7 << endl;	
	cout << endl;
	system("pause");
	return 0;
}