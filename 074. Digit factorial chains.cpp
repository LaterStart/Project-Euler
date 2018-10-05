/*
The number 145 is well known for the property that the sum of the factorial of its digits is equal to 145:

1! + 4! + 5! = 1 + 24 + 120 = 145

Perhaps less well known is 169, in that it produces the longest chain of numbers that link back to 169; it turns out that there are only three such loops that exist:

169 › 363601 › 1454 › 169
871 › 45361 › 871
872 › 45362 › 872

It is not difficult to prove that EVERY starting number will eventually get stuck in a loop. For example,

69 › 363600 › 1454 › 169 › 363601 (› 1454)
78 › 45360 › 871 › 45361 (› 871)
540 › 145 (› 145)

Starting with 69 produces a chain of five non-repeating terms, but the longest non-repeating chain with a starting number below one million is sixty terms.

How many chains, with a starting number below one million, contain exactly sixty non-repeating terms?
*/
// Completed on Fri, 15 Dec 2017
#include <iostream>
#include <string>
using namespace std;

int main() {
	unsigned int limit = 1000000;
	unsigned int factorialTable[10] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
	unsigned int x, count, c, t;
	string tmp;
	c = 0;
	bool * skips = new bool[2177281]();
	unsigned long * lenghts = new unsigned long[2177281];	
	bool repeat;

	string number; int num;
	for (int i = 1; i < limit; i++) {
		count = 1;
		if (skips[i]) {			
			count += lenghts[i];
			if (count < 60)
				continue;
			else if (count == 60) {
				c++;
				continue;
			}
		}
		string * terms = new string[60]();
		number = to_string(i);
		num = i;
		repeat = false;
		do {
			x = 0;
			for (int i = 0; i < number.length(); i++) {
				x += factorialTable[number[i] - '0'];
			}
			if (skips[x]) {
				count += lenghts[x];
				break;
			}
			number = to_string(x);
			if (x == num)break;
			terms[count] = number;
			for (int j = 1; j < count; j++) {
				if (number == terms[j]) {
					repeat = true;
					break;
				}
			}
			if (repeat)break;
			count++;
		} while (true);		
		if (count == 60) {
			c++;
			cout << i << endl;
		}	
		else {
			for (int j = 1; j < count; j++) {
				if (terms[j] != "") {
					x = stoull(terms[j]);
					if (skips[x])continue;
					lenghts[x] = count - j;
					skips[x] = 1;
				}
			}
		}
		delete[]terms;
	}
	cout << c << endl;
	system("pause");
	return 0;
}