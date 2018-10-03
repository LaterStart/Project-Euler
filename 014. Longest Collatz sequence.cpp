/* 	The following iterative sequence is defined for the set of positive integers:

n › n/2 (n is even)
n › 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 › 40 › 20 › 10 › 5 › 16 › 8 › 4 › 2 › 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million. */
// Completed on Thu, 17 Aug 2017
#include <iostream>
using namespace std;

int main() {

	int64_t term = 0;
	int64_t div = 0;
	int64_t n = 0;
	int64_t longest = 0;
	int64_t num = 0;

	for (int64_t i = 999999; i > 0; i--) {
		term = 0;
		for (div = i; div != 1; term++) {
			if (div % 2 == 0) {
				n = div / 2;
			}
			else {
				n = div * 3 + 1;
			}
			div = n;
		}
		if (term + 1 > longest) {
			longest = term + 1;
			num = i;
		}		
	}
	cout << longest << " "<<num<<endl;



	system("pause");
	return 0;
}