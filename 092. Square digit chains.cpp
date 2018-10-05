/*
A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 › 32 › 13 › 10 › 1 › 1
85 › 89 › 145 › 42 › 20 › 4 › 16 › 37 › 58 › 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?
*/
// Completed on Sun, 22 Oct 2017
#include <iostream>
#include <string>
using namespace std;

int main() {
	string num;
	int tmp, mem, tc, x;
	int count = 0;
	int *nums = new int[568];
	int *tmps = new int[500];
	for (int i = 567; i > 0; i--) {
		nums[i] = NULL;
	}
	for (int i = 9999999; i > 0; i--) {
		num = to_string(i);
		mem = 0; tmp = 0; tc = 0;
		for (int j = 0;; j++) {
			for (int k = 0; k < num.length(); k++) {
				tmp += pow(num[k] - '0', 2);
			}
			if (nums[tmp] != NULL) {
				tmp = nums[tmp];
			}
			else {
				tmps[tc] = tmp;
				tc++;
			}
			if (tmp == 1) {
				for (int t = 0; t < tc; t++) {
					x = tmps[t];
					tc = 0;
					tmps[t] = NULL;
					nums[x] = 1;
					tmp = 0;
				}
				break;
			}
			else if (tmp == 89) {
				for (int t = 0; t < tc; t++) {
					x = tmps[t];
					tc = 0;
					tmps[t] = NULL;
					nums[x] = 89;
					tmp = 0;
				}
				count++;
				break;
			}
			else {
				num = to_string(tmp);
				tmp = 0;
			}
		}
	}
	cout << count << endl;
	system("pause");
	return 0;
}