/*
Let d(n) be defined as the sum of proper divisors of n(numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ? b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/
// Completed on Sat, 16 Sep 2017
#include <iostream>
using namespace std;

int main() {
	const int N = 100000;
	int polje[N][2];
	int sum=0;

	for (int i = 1; i< N; i++) {
		for (int j = 1; j < i; j++) {
			if(i%j==0){
				sum += j;
			}
		}
		polje[i][0] = i;
		polje[i][1] = sum;
		sum = 0;
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (polje[i][1] == polje[j][0] && polje[i][0] == polje[j][1] && i!=j) {
				sum += i;
			}
		}
	}
	cout << sum << endl;

	system("pause");
	return 0;
}