/*
Some positive integers n have the property that the sum [ n + reverse(n) ] consists entirely of odd (decimal) digits. 
For instance, 36 + 63 = 99 and 409 + 904 = 1313. We will call such numbers reversible; so 36, 63, 409, and 904 are reversible.
Leading zeroes are not allowed in either n or reverse(n).

There are 120 reversible numbers below one-thousand.

How many reversible numbers are there below one-billion (10^9)?
*/
// Completed on Tue, 27 Feb 2018
#include <iostream>
#include <time.h>
using namespace std;

int main() {
	clock_t tStart = clock();
	int limit = pow(10, 9);
	int count = 0;
	int n1, n2, n3;
	bool skip;
	for (int i = 1; i < limit; i++) {
		n1 = i;
		if (n1 % 10 == 0)
			continue;
		n2 = 0;
		while (n1){
			n2 *= 10;
			n2 += n1 % 10;
			n1 /= 10;
		}
		n3 = i + n2;
		skip = false;
		while (n3) {
			if ((n3 % 10) % 2 == 0) {
				skip = true;
				break;
			}
			else n3 /= 10;
		}
		if (skip)
			continue;
		else	count++;
	}	
	cout << count << endl;
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	system("pause");
	return 0;
}