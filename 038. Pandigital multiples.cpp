/*
Take the number 192 and multiply it by each of 1, 2, and 3:

    192 × 1 = 192
    192 × 2 = 384
    192 × 3 = 576

By concatenating each product we get the 1 to 9 pandigital, 192384576. We will call 192384576 the concatenated product of 192 and (1,2,3)

The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4, and 5, giving the pandigital, 918273645, which is the concatenated product of 9 and (1,2,3,4,5).

What is the largest 1 to 9 pandigital 9-digit number that can be formed as the concatenated product of an integer with (1,2, ... , n) where n > 1?
*/
// Completed on Sun, 8 Oct 2017
#include <iostream>
#include <string>
using namespace std;

bool pandigital;
bool isPandigital(string number) {
	pandigital = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (i != j) {
				if (number[i]-'0' == 0 || number[i] == number[j]) {
					pandigital = false;
					break;
				}
			}
		}
	}
	return pandigital;
}

int main() {
	string tmp;
	int temp;
	unsigned int pandigitals[100];
	int n = 0;
	for (int i = 1;i<10000;i++) {
		tmp = "";
		for (int j = 1;j<10; j++) {
			temp = i*j;
			tmp += to_string(temp);
			if (tmp.length() > 9) {
				break;
			}
			if (tmp.length() == 9) {
				if (isPandigital(tmp)) {
					pandigitals[n] = stoi(tmp);
					n++;
				}
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (pandigitals[i] > max) {
			max = pandigitals[i];
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}