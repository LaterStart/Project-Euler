/*
The nth term of the sequence of triangle numbers is given by, tn = 1n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. 
If the word value is a triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common English words, how many are triangle words?
*/
// Completed on Sun, 8 Oct 2017
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream file;
	string words[2000][2];
	string read;
	int n = 0;
	file.open("words.txt");
	if (file.is_open()) {
		string delimiter = ",";
		string token;
		size_t pos = 0;
		while(getline(file,read)){
			while ((pos = read.find(delimiter)) != string::npos) {
				token = read.substr(0, pos);
				words[n][0] = token;
				n++;
				read.erase(0, pos + delimiter.length());
			}
			words[n][0] = read;
			n++;
		}
	}
	file.close();
	string tmp;
	int p;
	int sum;
	for (int i = 0; i < n; i++) {
		tmp = words[i][0];
		tmp.erase(0, 1);
		p = tmp.length() - 1;
		tmp.erase(p, 1);
		words[i][0]=tmp;
		sum = 0;
		for (int j = 0; j < words[i][0].length(); j++) {
			sum += ((words[i][0][j] - 0) - 64);
		}	
		words[i][1] = to_string(sum);		
	}
	double x;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 1;; j++) {
			x = static_cast<double>((static_cast<double>(j) / static_cast<double>(2)) * (static_cast<double>(j) + static_cast<double>(1)));
			if (x > stoi(words[i][1])) {
				break;
			}	
			if (stoi(words[i][1]) == x) {
				count++;
			}
		}		
	}
	cout << count << endl;
	system("pause");
	return 0;
}