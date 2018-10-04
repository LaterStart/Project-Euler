/*
Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?
*/
// Completed on Thu, 5 Oct 2017
#include <iostream>
using namespace std;

int main() {

	int dif = 2;
	int side = 0;
	int numbers[10000];
	int n = 0;
	int i = 1;
	int sum = 0;

	numbers[n] = 1;
	n++;
	i += dif;
	for (; ; i+=dif) {
		numbers[n] = i;
		n++;
		side++;
		if (side == 4) {
			dif += 2;
			side = 0;
		}
		if (dif == 1002) {
			break;
		}		
	}
	for (int i = 0; i < n; i++) {
		sum += numbers[i];
	}
	cout << sum << endl;

	system("pause");
	return 0;
}