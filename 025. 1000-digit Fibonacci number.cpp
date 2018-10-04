/* The Fibonacci sequence is defined by the recurrence relation :
Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be :

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144

The 12th term, F12, is the first term to contain three digits.
What is the index of the first term in the Fibonacci sequence to contain 1000 digits ?*/
// Completed on Tue, 19 Sep 2017
#include <iostream>
using namespace std;

int main() {

	int digitsLimit;
	int elements;
	int x, z, i;
	int fn2, fn1;

	cout << "Enter desired digits limit: " << flush;
	cin >> digitsLimit;

	elements = digitsLimit * 100;

	//initialization of main array
	int ** brojevi = new int*[elements];
	for (int i = 0; i < elements; i++) {
		brojevi[i] = new int[digitsLimit + 1];
		for (int j = 0; j < digitsLimit + 1; j++) {
			brojevi[i][j] = 0;
		}
	}

	//first four items initialization 
	z = 1;
	fn1 = 1;
	fn2 = 1;
	for (i = 2;i<4; i++) {
		x = fn1 + fn2;
		fn1 = fn2;
		fn2 = x;
		do {
			if (x < 10) {
				brojevi[i][z] = x;
				z++;
				x = 0;
			}
			else {
				brojevi[i][z] = x % 10;
				z++;
				x /= 10;
			}
		} while (x > 0);
		brojevi[i][0] = z - 1;
		z = 1;
	}
	brojevi[0][0] = 1;
	brojevi[0][1] = 1;
	brojevi[1][0] = 1;
	brojevi[1][1] = 1;

	//adding other items in fibonnaci sequence
	x = 0;
	do {
		z = 1;
		for (int j = 1; j <= brojevi[i - 1][0]; j++) {
			x += brojevi[i - 1][j] + brojevi[i - 2][j];

			if (x < 10) {
				brojevi[i][z] = x;
				z++;
				x = 0;
			}
			else {
				brojevi[i][z] = x % 10;
				z++;
				x /= 10;
			}
		}
		if (x > 0) {
			brojevi[i][z] = x;
			z++;
			x = 0;
		}
		brojevi[i][0] = z - 1;
		if (z-1 == digitsLimit) {
			i++;
			break;
		}
		z = 1;
		i++;
	} while (true);

	cout <<"Item index: "<< i << endl;
	system("pause");
	return 0;
}