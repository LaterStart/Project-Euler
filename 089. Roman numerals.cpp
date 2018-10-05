// Completed on Sat, 30 Dec 2017
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string RomanNumeral(int value) {
	int n = value;
	int i = 0, j = 0;
	do {
		n /= 10;
		i++; j++;
	} while (n > 0); j--;
	n = value;
	int * number = new int[i];
	do {
		number[j--] = n % 10;
		n /= 10;
	} while (n > 0);
	string roman = "";
	string tmp = "";
	for (j = i - 1; j >= 0; j--) {
		if (number[j] == 0) continue;
		else if (j == i - 1) {
			if (number[j] == 9 && value >= 9) roman += "IX";
			else if (number[j] == 4 && value >= 4) roman += "IV";
			else if (number[j] == 5) roman += 'V';
			else if (number[j] > 5) {
				roman += 'V';
				n = number[j] - 5;
				while (n-- > 0) roman += 'I';
			}
			else {
				n = number[j];
				while (n-- > 0) roman += 'I';
			}
		}
		else if (j == i - 2) {
			if (number[j] == 1) {
				tmp = 'X';
				roman = tmp + roman;
			}
			else if (number[j] == 9 && value >= 90) {
				tmp = "XC";
				roman = tmp + roman;
			}
			else if (number[j] == 4 && value >= 40) {
				tmp = "XL";
				roman = tmp + roman;
			}
			else if (number[j] == 5) {
				tmp = 'L';
				roman = tmp + roman;
			}
			else if (number[j] > 5) {
				tmp = 'L';
				n = number[j] - 5;
				while (n-- > 0) tmp += 'X';
				roman = tmp + roman;
			}
			else {
				n = number[j];
				tmp = "";
				while (n-- > 0)tmp += 'X';
				roman = tmp + roman;
			}
		}
		else if (j == i - 3) {
			if (number[j] == 1) {
				tmp = 'C';
				roman = tmp + roman;
			}
			else if (number[j] == 9 && value >= 900) {
				tmp = "CM";
				roman = tmp + roman;
			}
			else if (number[j] == 4 && value >= 400) {
				tmp = "CD";
				roman = tmp + roman;
			}
			else if (number[j] == 5) {
				tmp = 'D';
				roman = tmp + roman;
			}
			else if (number[j] > 5) {
				n = number[j] - 5;
				tmp = 'D';
				while (n-- > 0)tmp += 'C';
				roman = tmp + roman;
			}
			else {
				n = number[j];
				tmp = "";
				while (n-- > 0)tmp += 'C';
				roman = tmp + roman;
			}
		}
		else {
			if (number[j] == 1) roman = 'M' + roman;
			else {
				n = number[j];
				tmp = "";
				while (n-- > 0)tmp += 'M';
				roman = tmp + roman;
			}
		}
	}
	delete[]number;
	return roman;
}

int main() {
	ifstream read;
	string table[1000];
	int savings = 0;
	read.open("roman.txt");
	if (read.is_open()) {
		int i = 0;
		do {
			read >> table[i++];
		} while (!read.eof());
	}
	read.close();
	int value, size;
	string tmp;
	for (int i = 0; i < 1000; i++) {
		value = 0;
		for (size_t j = 0; j < table[i].length(); j++) {
			if (table[i][j] == 'M') value += 1000;
			else if (table[i][j] == 'D') value += 500;
			else if (table[i][j] == 'C') value += 100;
			else if (table[i][j] == 'L') value += 50;
			else if (table[i][j] == 'X') value += 10;
			else if (table[i][j] == 'V') value += 5;
			else if (table[i][j] == 'I') value += 1;
		}
		for (size_t j = 0; j < table[i].length() - 1; j++) {
			tmp = table[i][j];
			tmp += table[i][j + 1];
			if (tmp == "CM") value -= 200;
			else if (tmp == "XC") value -= 20;
			else if (tmp == "IX") value -= 2;
			else if (tmp == "CD") value -= 200;
			else if (tmp == "XL") value -= 20;
			else if (tmp == "IV") value -= 2;
		}
		size = RomanNumeral(value).length();
		if (size < table[i].length()) savings += (table[i].length() - size);
	}
	cout << savings << endl;
	system("pause");
	return 0;
}