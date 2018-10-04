/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.
HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.
*/
// Completed on Sat, 7 Oct 2017
#include <iostream>
#include <string>
using namespace std;

int main() {

	unsigned int x;
	int polje[100];
	string tmp;
	bool skip;
	bool possible;
	int n = 0;
	for (int i = 1; i < 10000; i++) {
		for (int j = 1; j < 10000; j++) {
			x = i*j;
			if (x > 1234 && x < 9876) {
				tmp = to_string(x);
				tmp += to_string(i);
				tmp += to_string(j);
				skip = false;
				possible = true;
				if (tmp.length() == 9) {
					for (int m = 0; m < tmp.length(); m++) {
						if (tmp[m] - '0' == 0) {
							possible = false;
							break;
						}
					}
					if (possible) {
						for (int k = 0; k < tmp.length(); k++) {
							for (int l = 0; l < tmp.length(); l++) {
								if (k != l) {
									if (tmp[k] == tmp[l]) {
										skip = true;
										break;
									}
								}
							}
						}
						if (!skip) {
							polje[n] = x;
							n++;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j && polje[i] == polje[j]) {
				polje[i] = 0;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += polje[i];
	}
	cout << sum << endl;

	system("pause");
	return 0;
}