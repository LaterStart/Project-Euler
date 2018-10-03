// If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
// Find the sum of all the multiples of 3 or 5 below 1000.
// Completed on Thu, 27 Jul 2017
#include <iostream>
using namespace std;

int main() {
	int a = 3;
	int b = 5;
	int sum = 0;

	for (int i = 0; i < 1000; i++) {
		if (i%a == 0 && i%b == 0) {
			sum += i;
		}
		else {
			if (i%b == 0 && i%a != 0) {
				sum += i;
			}
			if (i%a == 0 && i%b != 0) {
				sum += i;
			}
		}
	}
	cout << sum << endl;

	system("pause");
	return 0;
}