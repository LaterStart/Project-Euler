/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. 
Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/
// Completed on Mon, 18 Sep 2017
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream read;
	string polje[5163];
	read.open("names.txt");
	if (read.is_open()) {
		string file;
		read >> file;

		string delimiter = ",";
		size_t pos = 0;
		string token;
		int i = 0;
		while ((pos = file.find(delimiter)) != string::npos) {
			token = file.substr(0, pos);
			polje[i] = token;
			file.erase(0, pos + delimiter.length());
			i++;
		}
		polje[i] = file;
	}
	read.close();

	int n;
	for (int i = 0; i < 5163; i++) {
		n = polje[i].length();
		for (int j = 0; j < n - 1; j++) {
			polje[i][j] = polje[i][j + 1];
		}
		polje[i].resize(n - 2);
	}
	bool check;
	int a = 65;
	string sorted[5163];
	string tmp;
	n = 0;
	int m = 0;
	int max = 0;
	int min = 0;
	bool go;
	for (int j = 0; j < 26; j++) {
		for (int i = 0; i < 5163; i++) {
			if ((polje[i][0]) == (a + j)) {
				sorted[n] = polje[i];
				n++;
			}
		}
		do {
			check = false;
			for (int i = m; i < n - 1; i++) {
				if (sorted[i + 1].length() < sorted[i].length()) {
					tmp = sorted[i];
					sorted[i] = sorted[i + 1];
					sorted[i + 1] = tmp;
					check = true;
				}
			}
		} while (check);
		for (int i = m; i < n; i++) {
			if (sorted[i].length() > max)
				max = sorted[i].length();
		}
		min = 1;
		do {
			do {				
				check = false;
				for (int i = m; i < n - 1; i++) {
					if (sorted[i].length() >= min && sorted[i + 1].length() >= min) {
						for (int k = 1; k < min; k++) {
							if (sorted[i + 1][0 + k] != sorted[i][0 + k]) {
								go = false;
								break;
							}
						}
						if (go == true && sorted[i + 1][min] < sorted[i][min]) {
							tmp = sorted[i];
							sorted[i] = sorted[i + 1];
							sorted[i + 1] = tmp;
							check = true;
						}
					}
					go = true;
				}
			} while (check);
			min++;
		} while (min <= max);
		m = n;
	}
	unsigned long long SUM = 0;
	long long sum = 0;
	for (int i = 0; i < 5163; i++) {
		for (int j = 0; j < sorted[i].length(); j++) {
			sum += sorted[i][j] - a+1;
		}
		sum = sum*(i + 1);
		SUM += sum;
		sum = 0;		
	}
	cout << SUM << endl;

	system("pause");
	return 0;
}