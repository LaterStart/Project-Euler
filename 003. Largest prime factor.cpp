// The prime factors of 13195 are 5, 7, 13 and 29.
// What is the largest prime factor of the number 600851475143 ?
// Completed on Thu, 27 Jul 2017
#include <iostream>
using namespace std;

int main() {

	long long a = 600851475143;
	long long i = 2;
	long long b = 0;
	long long j = 0;
	long long x = 0;

	while (b != 1) {
		while (a%i != 0) {
			i++;
		}
		if (a == i) {
			x = a;
			break;
		}
		while (b%i == 0) {
			b = a / i;
			a = b;
			j++;
		}
		a = b;
	}	
	cout << x << endl;
	system("pause");
	return 0;
}