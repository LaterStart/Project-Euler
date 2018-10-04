/*
The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, and containing two digits in the numerator and denominator.

If the product of these four fractions is given in its lowest common terms, find the value of the denominator.
*/
// Completed on Sat, 7 Oct 2017
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	double x;
	int a, b, c, d;
	bool trivial;
	int productA=1;
	int productB= 1;
	for (int i = 10; i < 100; i++) {
		for (int j = 10; j < 100; j++) {
			x = static_cast<double>(i) / static_cast<double>(j);
			if (x < 1) {
				a = i / 10;	b = i % 10;	c = j / 10;	d = j % 10;
				trivial = false;
				if (b == 0 || d == 0) {
					trivial = true;
				}
				if (!trivial) {
					if (static_cast<double>(a) / static_cast<double>(d) == x && b==c) {
						cout << i << "/" << j << "\t" << x << "\t" << a << "/" << c << endl;
						productA *= i;
						productB *= j;
					}
				}
			}
		}
	}
	cout << endl<<productA << "/"<<productB<<endl;
	int max = 1;
	for (int i = 1;i<=productA; i++) {
		if (productA % i == 0 && productB % i == 0) {
			if (i > max) {
				max = i;
			}
		}
	}
	cout << productA/max <<"/"<<productB / max << endl;
	system("pause");
	return 0;
}