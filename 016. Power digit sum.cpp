/* 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2^1000?
*/
// Completed on Fri, 18 Aug 2017
#include <iostream>
#include <sstream>
using namespace std;

int main() {

	double number = pow(2, 1000);

	std::ostringstream converter;
	converter.precision(0);
	converter <<fixed << number;
	std::string text = converter.str();

	int sum = 0;
	for (int i = 0; i < text.length(); i++) {
		sum += text[i]-'0';
	}

	cout << sum << endl;

	system("pause");
	return 0;
}