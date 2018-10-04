/*
We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?
*/
// Completed on Sun, 8 Oct 2017
#include <iostream>
#include <string>
using namespace std;

bool prime;
bool pandigital;
bool isPrime(unsigned int n) {
	prime = true;
	for (unsigned int j = 2; j <= sqrt(n); j++) {
		if (n%j == 0) {
			prime = false;
			break;
		}
	}	
	return prime;
}
bool isPandigital(string number) {
	pandigital = true;
	for (int i = 0; i < number.length(); i++) {
		if (number[i] - '0' == 0 || number[i] -'0' > number.length()) {
			pandigital = false;
			break;
		}
		for (int j = 0; j < number.length(); j++) {
			if (i != j) {
				if (number[i] == number[j]) {
					pandigital = false;
					break;
				}
			}
		}
	}
	return pandigital;
}
int main() {
	unsigned int max = 0;
	for (unsigned int i = 2; i <= 987654321; i++) {
		if ((i % 2 == 0) || (i % 3 == 0) || (i % 5 == 0) || (i % 10 == 0)) {
			continue;
		}
		if (isPandigital(to_string(i))) {
			if (isPrime(i)) {
				cout << i << endl;
				if (i > max) {
					max = i;
				}
			}
		}		
	}
	cout << max << endl;
	system("Pause");
	return 0;
}