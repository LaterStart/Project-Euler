/*Find the unique positive integer whose square has the form 1_2_3_4_5_6_7_8_9_0,
where each “_” is a single digit.*/
// Completed on Wed, 25 Oct 2017
#include <iostream>
#include <string>
using namespace std;

int main() {
	string num;
	unsigned int min = sqrt(static_cast<unsigned long long>(1121314151617181910));
	unsigned int max = sqrt(static_cast<unsigned long long>(1929394959697989990));
	unsigned long long x;
	for (unsigned long long i = max; i >= min; i--) {
		x = static_cast<unsigned long long>(i*i);
		num = to_string(x);
		if (num[18] == 0+'0' && num[16] == 9 + '0' && num[14] == 8 + '0' && num[12] == 7 + '0' && num[10] == 6 + '0' && num[8] == 5 + '0' && num[6] == 4 + '0' && num[4] == 3 + '0' && num[2] == 2 + '0' && num[0] == 1 + '0') {
			cout << i << endl;
			break;
		}
	}
	system("pause");
	return 0;
}