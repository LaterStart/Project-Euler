/* 	The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
	Find the sum of all the primes below two million. */
// Completed on Thu, 3 Aug 2017
#include <iostream>
using namespace std;

int main() {

	int x;
	int max;
	int p = 0;
	int64_t sum = 0;

	for (int i = 2; i < 2000000; i++) {
		max = pow(i, 0.5);
		if ((i > 2 && i % 2 == 0) || (i > 3 && i % 3 == 0) || (i>5 && i%5==0) || (i%10==0)) {
			continue;
		}
		else {
			x = 0;
			for (int j = 2; j <= max; j++) {
				if (i%j == 0) {
					x++;
				}
				
				}
			if (x == 0) {
				sum += i;
			}				
		}
		
	}
	cout << sum << endl;
	system("pause");
	return 0;
}