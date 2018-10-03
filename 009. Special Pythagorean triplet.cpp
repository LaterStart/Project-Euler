/* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc. */
// Completed on Wed, 2 Aug 2017
#include <iostream>
using namespace std;

int main() {

	int sum = 1000;
	int product = 0;

	for (int a = 1; a < sum; a++) {
		for (int b = 1; b < sum; b++) {
			for (int c = 1; c < sum; c++) {
				if (a + b + c == sum && c > b && b>a && pow(a, 2) + pow(b, 2) == pow(c, 2)) {
					product = a*b*c;
					cout << a << " " << b << " " << c << endl;
					cout << product << endl;
				}
			}
		}
	}

	system("pause");
	return 0;
}