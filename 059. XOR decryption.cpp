// Completed on Sat, 21 Oct 2017
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream file;
	string read;
	int n = 0;
	int message[1500];
	file.open("cipher.txt");
	if (file.is_open()) {
		string delimiter = ",";
		string token;
		size_t pos;
		while (getline(file, read)) {
			pos = 0;
			while ((pos = read.find(delimiter)) != string::npos) {
				token = read.substr(0, pos);
				message[n] = stoi(token);
				n++;
				read.erase(0, pos + delimiter.length());
			}
			message[n] = stoi(read);
			n++;
		}
	}
	file.close();
	int max, count;
	int key[3];
	for (int z = 0; z < 3; z++) {
		max = 0;
		for (int i = 0; i <= 255; i++) {
			count = 0;
			if (z == 0) {

				for (int j = 0; j < n; j++) {
					if (message[j] == i) {
						count++;
					}
				}
				if (count > max) {
					max = count;
					key[0] = i;
				}
			}
			if (z == 1) {
				if (i != key[0]) {
					for (int j = 0; j < n; j++) {
						if (message[j] == i) {
							count++;
						}
					}
					if (count > max) {
						max = count;
						key[1] = i;
					}
				}
			}
			if (z == 2) {
				if (i != key[0] && i != key[1]) {
					for (int j = 0; j < n; j++) {
						if (message[j] == i) {
							count++;
						}
					}
					if (count > max) {
						max = count;
						key[2] = i;
					}
				}
			}
		}
	}
	key[0] ^= 32;
	key[1] ^= 32;
	key[2] ^= 32;
	string password;
	int tmpDecrypt;
	int z;
	int sum;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (i != j && i != k && j != k) {
					password = string() + char(key[i]) + char(key[j]) + char(key[k]);
					cout << password << endl;
					string decrypted;
					z = 0;
					for (int i = 0; i < n; i++) {
						if (z == 0) {
							tmpDecrypt = message[i] ^ (password[z]);
							decrypted += tmpDecrypt;
							z++;
						}
						else if (z == 1) {
							tmpDecrypt = message[i] ^ (password[z]);
							decrypted += tmpDecrypt;
							z++;
						}
						else if (z == 2) {
							tmpDecrypt = message[i] ^ (password[z]);
							decrypted += tmpDecrypt;
							z = 0;
						}
					}
					sum = 0;
					cout << decrypted << endl;
					for (int m = 0; m < decrypted.length(); m++) {
						sum += decrypted[m];
					}
					cout << sum << endl;
				}
			}
		}
	}
	system("pause");
	return 0;
}