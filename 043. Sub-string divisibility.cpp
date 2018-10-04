/*
The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

    d2d3d4=406 is divisible by 2
    d3d4d5=063 is divisible by 3
    d4d5d6=635 is divisible by 5
    d5d6d7=357 is divisible by 7
    d6d7d8=572 is divisible by 11
    d7d8d9=728 is divisible by 13
    d8d9d10=289 is divisible by 17

Find the sum of all 0 to 9 pandigital numbers with this property.
*/
// Completed on Tue, 10 Oct 2017
#include <iostream>
#include <string>
using namespace std;

string divisibility(string number, int div, int div2, int n) {
	string tmp, tmp2;
	string possibleNumber="";
	bool possible = false;

	tmp = to_string(n) + number[0] + number[1];
	if (stoi(tmp) % div == 0) {
		possible = true;
	}
	if (possible) {
		for (int j = 2; j < number.length(); j++) {
			tmp2 += string() + number[j];
		}
		tmp += tmp2;
		for (int p = 0; p < tmp.length(); p++) {
			for (int r = 0; r < tmp.length(); r++) {
				if (p != r && tmp[p] == tmp[r]) {
					possible = false;
					break;
				}
			}
		}
		if (possible) {
			number = string() + tmp[1] + tmp[2] + tmp[3];
			if (stoi(number) % div2 == 0) {
				possibleNumber = tmp;
			}
		}
	}
	return possibleNumber;
}


int main() {
	string tmp, tmp2, number;
	int primes[] = { 2,3,5,7,11,13,17 };
	bool possible;
	string numbers[50];
	string numbersTmp[50];
	int n = 0;
	int n2;
	int div1, div2;
	string possibleNum;
	for (int i = 1; i < 1000; i++) {
		if (i % 17 == 0) {
			tmp = to_string(i);
			possible = true;
			if (tmp.length() < 3) {
				tmp2 = "";
				for (int m = 3; m > tmp.length(); m--) {
					tmp2 += "0";
				}
				tmp2 += tmp;
				tmp = tmp2;
			}
			for (int p = 0; p < tmp.length(); p++) {
				for (int r = 0; r < tmp.length(); r++) {
					if (p != r && tmp[p] == tmp[r]) {
						possible = false;
						break;
					}
				}
			}
			if (possible) {
				numbers[n] = tmp;
				n++;
			}
		}
	}	
	n2 = 0;
	for (int d = 5; d >= 0; d--) {
		div1 = primes[d];
		div2 = primes[d + 1];
		if (n2 > 0) {
			n = n2;
		}
		n2 = 0;
		for (int i = 0; i < n; i++) {
			number = numbers[i];
			for (int j = 0; j < 10; j++) {
				possibleNum = divisibility(number, div1, div2, j);
				if (possibleNum != "") {
					numbersTmp[n2] = possibleNum;
					n2++;
				}
			}
		}
		for (int m = 0; m < n2; m++) {
			numbers[m] = numbersTmp[m];
		}
	}
	long long sum = 0;
	for (int i = 0; i < n2; i++) {
		number = numbers[i];
		for (int j = 1; j < 10; j++) {
			tmp = to_string(j) + number;
			possible = true;
			for (int p = 0; p < tmp.length(); p++) {
				for (int r = 0; r < tmp.length(); r++) {
					if (p != r && tmp[p] == tmp[r]) {
						possible = false;
						break;
					}
				}
			}
			if (possible) {
				sum += stoll(tmp);
			}
		}
	}
	cout << sum << endl;

	system("pause");
	return 0;
}