/*
It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.
*/
// Completed on Sat, 14 Oct 2017
#include <iostream>
#include <string>
using namespace std;

bool sameDigits(string a, string b) {
	bool same=true;
	int count;
	for (int i = 0; i < a.length(); i++) {
		count = 0;
		for (int j = 0; j < b.length(); j++) {
			if (b[i] == a[j]) {
				count++;
			}
		}
		if (count < 1) {
			same = false;
			break;			
		}
	}
	return same;
}
bool differentDigits(string n) {
	int diff = 0;
	for (int i = 0; i < n.length(); i++) {
		for (int j = 0; j < n.length(); j++) {
			if (i != j && n[i] == n[j]) {
				return false;
				break;
			}
		}
	}
	return true;
}
int main() {
	string a, b, c, d, e, f;
	for (int i = 1; ; i++) {
		a = to_string(i);
		b = to_string(i * 2);
		if (a.length() != b.length()) {
			continue;
		}
		if (differentDigits(a) && differentDigits(b) && sameDigits(a, b)) {
			c = to_string(i * 3);
			if (c.length() != b.length()) {
				continue;
			}
			if (differentDigits(c) && sameDigits(b, c)) {
				d = to_string(i * 4);
				if (d.length() != c.length()) {
					continue;
				}
				if (differentDigits(d) && sameDigits(c, d)) {
					e = to_string(i * 5);
					if (e.length() != d.length()) {
						continue;
					}
					if (differentDigits(e) && sameDigits(d, e)) {
						f = to_string(i * 6);
						if (f.length() != e.length()) {
							continue;
						}
						if (differentDigits(f) && sameDigits(e, f)) {
							cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
							break;
						}
					}
				}
			}

		}
	}

	system("pause");
	return 0;
}