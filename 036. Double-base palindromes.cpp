/*
The decimal number, 585 = 1001001001 2 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)
*/
// Completed on Sat, 7 Oct 2017
#include <iostream>
#include <string>
using namespace std;

int main() {
	string tmp;
	int i, x;
	bool palindrome;
	int sum = 0;
	for (int n = 1; n < 1000000; n++) {
		tmp = to_string(n);
		palindrome = true;
		for (int j = 0; j < tmp.length()/2; j++) {
			if (tmp[j] != tmp[(tmp.length() - 1) - j]) {
				palindrome = false;
				break;
			}
		}
		if (palindrome) {
			i = 0;
			tmp = "";
			x = n;
			do {
				tmp += to_string(x % 2);
				x /= 2;
				i++;
			} while (x > 0);
			for (int j = 0; j < tmp.length() / 2; j++) {
				if (tmp[j] != tmp[(tmp.length() - 1) - j]) {
					palindrome = false;
					break;
				}
			}
			if (palindrome) {
				sum += n;
			}
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}