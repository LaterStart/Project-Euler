/*The sum of the squares of the first ten natural numbers is, 1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 - 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.*/
// Completed on Mon, 31 Jul 2017
#include <iostream>
using namespace std;

int main() {

	int sum = 0;
	int	sum2 = 0;
	int Sum2 = 0;
	int dif = 0;

	for (int i = 1; i <= 100; i++) {
		sum += i;
		Sum2 += pow(i, 2);
	}
	sum2 = pow(sum, 2);
	dif = sum2 - Sum2;
	cout << dif << endl;

	system("pause");
	return 0;
}