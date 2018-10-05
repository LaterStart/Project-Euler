/*
Working from left-to-right if no digit is exceeded by the digit to its left it is called an increasing number; for example, 134468.

Similarly if no digit is exceeded by the digit to its right it is called a decreasing number; for example, 66420.

We shall call a positive integer that is neither increasing nor decreasing a "bouncy" number; for example, 155349.

Clearly there cannot be any bouncy numbers below one-hundred, but just over half of the numbers below one-thousand (525) are bouncy. In fact, the least number for which the proportion of bouncy numbers first reaches 50% is 538.

Surprisingly, bouncy numbers become more and more common and by the time we reach 21780 the proportion of bouncy numbers is equal to 90%.

Find the least number for which the proportion of bouncy numbers is exactly 99%.
*/
// Completed on Mon, 27 Nov 2017
#include <iostream>
#include <string>
using namespace std;

int main() {
	int N = pow(10,7); //search scope
	int X = to_string(N).length();

	string ** table = new string*[N]; //store increasing or decreasing numbers
	string tmp, value;
	bool * bouncy = new bool[N * 10](); //bouncy lookup
	int b = 0, n = 0, j = 0, x;
	double percent;
	double PERCENT = 99; //search percentage

	for (int i = 1; i < 10; i++) {
		table[n] = new string[2]();
		table[n][0] = to_string(i);
		table[n][1] = "0";	n++;
		bouncy[i] = 1;

		for (j = j; j < n; j++) {
			if (table[j][0].length() >= X) 	continue;
			for (int k = 0; k < 10; k++) {
				tmp = table[j][0];
				value = table[j][1];
				tmp.resize(tmp.length() + 1, k + '0');

				if (value == "0") {
					if (tmp[tmp.length() - 1] - '0' > tmp[tmp.length() - 2] - '0') x = 1;
					else if (tmp[tmp.length() - 1] - '0' < tmp[tmp.length() - 2] - '0') x = 2;
					else x = 0;
					table[n] = new string[2];
					table[n][0] = tmp;
					table[n][1] = to_string(x);
					bouncy[stoi(tmp)] = 1;
					n++;
				}
				else if (value == "1") {
					table[n] = new string[2];
					table[n][0] = tmp;
					x = (tmp[tmp.length() - 1] - '0' >= tmp[tmp.length() - 2] - '0') ? 1 : 2;
					if (x == 1) {
						table[n][1] = to_string(x);
						n++; bouncy[stoi(tmp)] = 1;

					}
				}
				else if (value == "2") {
					table[n] = new string[2];
					table[n][0] = tmp;
					x = (tmp[tmp.length() - 1] - '0' <= tmp[tmp.length() - 2] - '0') ? 2 : 1;
					if (x == 2) {
						table[n][1] = to_string(x);
						n++; bouncy[stoi(tmp)] = 1;
					}
				}
			}
		}
	}
	cout << "searching.." << endl;
	for (int i = 1; i < N; i++) {		
		if (bouncy[i] == NULL) {
			b++;
			percent = static_cast<double>(b) / i * 100;
			//cout << percent << " " << i << endl;
			if (percent >= PERCENT) {
				cout << i << endl;
				system("pause");
			}

		}
	}

	system("pause");
	return 0;
}