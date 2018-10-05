/*A common security method used for online banking is to ask the user for three random characters from a passcode. For example, if the passcode was 531278,
they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

The text file, keylog.txt, contains fifty successful login attempts.
Given that the three characters are always asked for in order, analyse the file so as to determine the shortest possible secret passcode of unknown length.*/
// Completed on Wed, 25 Oct 2017
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	ifstream read;
	read.open("keylog.txt");
	string keys[50];
	string tmp;
	int n = 0;
	if (read.is_open()) {
		while (read >> tmp) {
			keys[n] = tmp;
			n++;
		}
	}
	read.close();
	bool breakme;
	string numbers=" ";
	n = 1;
	for (int i = 48; i <= 57; i++) {
		breakme = false;
		for (int j = 0; j < 50; j++) {
			for (int k = 0; k < 3; k++) {
				if (keys[j][k] == i) {
					numbers += string() + char(i);
					n++;
					breakme = true;
					break;
				}
			}
			if (breakme) {
				break;
			}
		}
	}
	numbers[0] = n - 1+'0';
	int c, n1, n2;
	bool swap;
	char nn;
	do {
		swap = false;
		for (int i = 1; i < numbers[0]-'0'; i++) {
			breakme = false;
			for (int j = 0; j < 50; j++) {
				c = 0;
				for (int k = 0; k < 3; k++) {
					if (numbers[i] == keys[j][k] || numbers[i + 1] == keys[j][k]) {
						c++;
					}
				}
				if (c == 2) {
					breakme = true;
					for (int k = 0; k < 3; k++) {
						if (keys[j][k] == numbers[i]) {
							n1 = k;
						}
						if (keys[j][k] == numbers[i + 1]) {
							n2 = k;
						}
					}
					if (n1 > n2) {
						nn = numbers[i];
						numbers[i] = numbers[i + 1];
						numbers[i + 1] = nn;
						swap = true;
					}
				}
				if (breakme) {
					break;
				}
			}
		}
	} while (swap);
	for (int i = 1; i <= numbers[0] - '0'; i++) {
		cout << numbers[i];
	}
	cout << endl;
	system("pause");
	return 0;
}