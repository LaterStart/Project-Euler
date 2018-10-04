/*
In England the currency is made up of pound, £, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

It is possible to make £2 in the following way:

    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

How many different ways can £2 be made using any number of coins?
*/
// Completed on Fri, 6 Oct 2017
#include <iostream>
using namespace std;

int main() {
	int sum;
	int x = 0;

	for (int i = 0; i <= 200 / 100; i++) {
		for (int j = 0; j <= 200 / 50; j++) {
			for (int k = 0; k <= 200 / 20; k++) {
				for (int m = 0; m <= 200 / 10; m++) {
					for (int n = 0; n <= 200 / 5; n++) {
						for (int o = 0; o <= 200 / 2; o++) {
							for (int p = 0; p <= 200 / 1; p++) {
								sum = p * 1 + o * 2 + n * 5 + m * 10 + k * 20 + j * 50 + i * 100;
								if (sum == 200) {
									x++;
								}
							}
						}
					}
				}
			}
		}
	}

	cout << x+1 << endl;
	system("pause");
	return 0;
}