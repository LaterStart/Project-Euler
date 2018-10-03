/* If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in compliance with British usage. */
// Completed on Fri, 18 Aug 2017
#include <iostream>
using namespace std;

int main() {

	string brojevi[1001] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty"};
	brojevi[30] = "thirty"; brojevi[40] = "forty"; brojevi[50] = "fifty"; brojevi[60] = "sixty"; brojevi[70] = "seventy"; brojevi[80] = "eighty"; brojevi[90] = "ninety"; brojevi[100] = "hundred"; brojevi[1000] = "onethousand";
	
	int n = 0;
	int v = 0;
	for (int i = 20; i <= 1000; i++) {
		if (i % 10 == 0 && i<=100) {
			n = i;
			if (i == 100) {
				goto label;
			}
			continue;
		}
		if (i >= 100) {
		label:
			if (i == 100) {
				v = i / 100;
			}
			else {
				v = i / 100;
				if (i % 100 == 0) {
					if (i == 1000) {
					}
					else {
						brojevi[i] = brojevi[v] + brojevi[n];
					}
				}
				else {
					brojevi[i] = brojevi[v] + brojevi[n] + "and" + brojevi[i % 100];
				}
			}
		}
		
		else {
			brojevi[i] = brojevi[n] + brojevi[i % 10];
		}		
	}	
	int sum = 0;
	brojevi[100] = { "onehundred" };
	for (int i = 1; i <= 1000;i++) {
		sum += brojevi[i].length();
	}
	cout << sum << endl;

	system("pause");
	return 0;
}