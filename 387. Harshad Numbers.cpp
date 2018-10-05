/*
A Harshad or Niven number is a number that is divisible by the sum of its digits.
201 is a Harshad number because it is divisible by 3 (the sum of its digits.)
When we truncate the last digit from 201, we get 20, which is a Harshad number.
When we truncate the last digit from 20, we get 2, which is also a Harshad number.
Let's call a Harshad number that, while recursively truncating the last digit, always results in a Harshad number a right truncatable Harshad number.

Also:
201/3=67 which is prime.
Let's call a Harshad number that, when divided by the sum of its digits, results in a prime a strong Harshad number.

Now take the number 2011 which is prime.
When we truncate the last digit from it we get 201, a strong Harshad number that is also right truncatable.
Let's call such primes strong, right truncatable Harshad primes.

You are given that the sum of the strong, right truncatable Harshad primes less than 10000 is 90619.

Find the sum of the strong, right truncatable Harshad primes less than 1014.
*/
// Completed on Wed, 15 Nov 2017
#include <iostream>
#include <string>
using namespace std;

bool prime;
bool isPrime(unsigned long long n) {
	prime = true;
	for (unsigned long long j = 2; j <= sqrt(n); j++) {
		if (n%j == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

int main() {
	unsigned long long SUM = 0;
	int x = 0;
	string tmp, tmp2;
	string **numbers = new string*[100000];
	for (int i = 0; i < 100000; i++) {
		numbers[i] = new string[2];
	}
	int z = 0, y = 0;
	for (int i = 1; i < 10; i++) {
		tmp = to_string(i);
		numbers[z][0] = tmp;
		numbers[z][1] = to_string(i);  z++;
		for (y = y; y < z; y++) {
			tmp2 = numbers[y][0];
			if (tmp2.length() == 13) {
				continue;
			}
			tmp2.resize(tmp2.length() + 1);
			for (int j = 0; j < 10; j++) {
				tmp2[tmp2.length() - 1] = j + '0'; x = 0;
				for (int k = 0; k < tmp2.length(); k++) {
					x += tmp2[k] - '0';
				}
				if (stoull(tmp2) % x == 0) {
					numbers[z][0] = tmp2;
					numbers[z][1] = to_string(x); z++;
				}
			}
		}
	}
	for (int i = 0; i < z; i++) {
		if (isPrime((stoull(numbers[i][0])) / stoi(numbers[i][1]))) {
			tmp = numbers[i][0];
			tmp.resize(tmp.length() + 1);
			for (int h = 1; h < 10; h += 2) {
				tmp[tmp.length() - 1] = h + '0';
				if (tmp.length() >= 3 && isPrime(stoull(tmp))) {
					SUM += stoull(tmp);
				}
			}
		}
	}
	cout << endl << SUM << endl;
	system("pause");
	return 0;
}