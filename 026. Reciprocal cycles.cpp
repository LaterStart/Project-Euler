/*
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

    1/2	= 	0.5
    1/3	= 	0.(3)
    1/4	= 	0.25
    1/5	= 	0.2
    1/6	= 	0.1(6)
    1/7	= 	0.(142857)
    1/8	= 	0.125
    1/9	= 	0.(1)
    1/10	= 	0.1 

Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.
*/
// Completed on Tue, 19 Sep 2017
#include <iostream>
using namespace std;

int main() {

	int n;
	int n1;
	int cyc[1002];
	for (int i = 2; i<1000; i++) {
		n1 = 1 % i;
		n = n1;
		for (int j = 1; ; j++) {
			n *= 10;
			n %= i;
			if (n == n1) {
				cyc[i] = j;
				break;
			}
			else if (j > i){
				break;
			}
		}
	}
	int max = 0;
	int d;
	for (int i = 2; i < 1000; i++) {
		if (cyc[i] > max) {
			max = cyc[i];
			d = i;
		}
	}
	cout << d << " " << max << endl;

	system("pause");
	return 0;
}