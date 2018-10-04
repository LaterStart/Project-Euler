/*
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.
*/
// Completed on Sat, 7 Oct 2017
#include <iostream>
#include <string>
using namespace std;

int main() {
	unsigned long long f;
	int sum;
	string tmp;
	int SUM = 0;
	for (int n = 3; n<99999; n++) {
		tmp = to_string(n);
		sum = 0;
		for (int i = 0; i < tmp.length(); i++) {
			f = 1;			
			for (int j = 1; j <= (tmp[i]-'0'); j++) {
				f *= j;
			}
			sum += f;	
		}
		if (sum == n) {
			SUM += sum;
		}
	}
	cout << SUM << endl;
	system("pause");
	return 0;
}