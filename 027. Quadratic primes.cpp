/*Euler discovered the remarkable quadratic formula:

n2+n+41

It turns out that the formula will produce 40 primes for the consecutive integer values 0?n?39
. However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41

is clearly divisible by 41.

The incredible formula n2-79n+1601
was discovered, which produces 80 primes for the consecutive values 0?n?79

. The product of the coefficients, -79 and 1601, is -126479.

Considering quadratics of the form:

    n2+an+b

, where |a|<1000 and |b|?1000

where |n|
is the modulus/absolute value of n
e.g. |11|=11 and |-4|=4

Find the product of the coefficients, a
and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.*/
// Completed on Thu, 5 Oct 2017
#include <iostream>
using namespace std;

int main() {
	int counter;
	int prime = 0;
	int x;
	int max = 0;
	int z, y, v;

	for (int a = -999; a < 1000; a++) {
		for (int b = -1000; b <=1000; b++) {
			for (int n = 0 ; ; n++) {
				counter = 0;
				x = (n*n) + (a*n) + b;
				for (int i = 1; i < x; i++) {
					if (x%i == 0) {
						counter++;
					}
				}
				if (counter == 1) {
					n++;
				}
				else {
					if (n > max) {
						z = a;
						y = b;
						max = n-1;
					}
					break;
				}
			}			
		}
	}
	cout << max << endl;
	cout << z << "*" << y << "=" << z*y << endl;
	
	system("pause");
	return 0;
}