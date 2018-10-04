/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/
// Completed on Sun, 8 Oct 2017
#include <iostream>
#include <string>
using namespace std;

bool prime;
bool isPrime(int n) {
	prime = true;
	for (int j = 2; j <= sqrt(n); j++) {
		if (n%j == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

int main() {
	string tmp;
	bool truncatable;
	int pos;
	int sum = 0;
	int n = 0;
	for (int i = 10;n<11; i++) {
		if (isPrime(i)) {
			tmp = to_string(i);
			truncatable = true;
			while (tmp != "") {
				if (!isPrime(stoi(tmp)) || stoi(tmp) == 1) {
					truncatable = false;
					break;
				}				
				tmp.erase(0, 1);
			}			
			if (truncatable) {
				tmp = to_string(i);
				while (tmp != "") {
					if (!isPrime(stoi(tmp)) || stoi(tmp) == 1) {
						truncatable = false;
						break;
					}
					pos = tmp.length() - 1;
					tmp.erase(pos, 1);					
				}			
				if (truncatable) {
					n++;
					sum += i;
				}
			}
		}
	}
	cout << sum << endl;
	system("pause");
	return 0;
}