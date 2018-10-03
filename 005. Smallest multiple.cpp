// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20 ?
// Completed on Mon, 31 Jul 2017
#include <iostream>
using namespace std;

int main() {

	int number=1;
	int i = 1;
	bool check = false;

	do {
		if (number%i== 0) {			
			if (i == 20) {
				check = true;
			}
			i++;
			
		}
		else {
			number++;
			i = 1;
		}


	} while (check != true);

		cout << number << endl;


	system("pause");
	return 0;
}