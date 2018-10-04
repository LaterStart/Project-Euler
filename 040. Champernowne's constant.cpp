/*
An irrational decimal fraction is created by concatenating the positive integers:

0.123456789101112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000
*/
// Completed on Sun, 8 Oct 2017
#include <iostream>
#include <string>
using namespace std;

int main() {
	string number;
	int i = 0;
	while (number.length() < 1000000) {
		i++;
		number += to_string(i);
	}
	unsigned long long product;
	product = (number[0]-'0') * (number[9] - '0') * (number[99] - '0') * (number[999] - '0') * (number[9999] - '0') * (number[99999] - '0') * (number[999999] - '0');
	cout << product<< endl;


	system("Pause");
	return 0;
}
