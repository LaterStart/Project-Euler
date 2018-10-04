/*
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 14 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
*/
// Completed on Fri, 6 Oct 2017
#include <iostream>
using namespace std;

int main() {
	int x, n, sum;
	int SUM = 0;

	for (int i = 2; ;i++) {
		n = i;
		sum = 0;
		do{
			x = n % 10;
			sum += pow(x, 5);
			n /= 10;
			if (n == 0) {
				break;
			}
		} while (true);
		if (sum == i) {
			cout << i;
			SUM += i;
			cout << " " << SUM << endl;
			sum = 0;
		}
		else {
			sum = 0;
		}
	}
	return 0;
}