/*
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ? 1000, is the number of solutions maximised?
*/
// Completed on Sun, 8 Oct 2017
#include <iostream>
using namespace std;

int main() {
	int c, sum;
	int tmp;
	double temp;
	int perimiters[1000][2];
	int n = 0;
	bool neW;
	for (int a = 1; a < 1000; a++) {
		for (int b = 1; b < 1000; b++) {
			tmp = (pow(a, 2) + pow(b, 2));
			temp = sqrt(tmp);
			if (floor(temp) == temp) {
				c = temp;
				sum = a + b + c;
				if (sum <= 1000) {
					if (n > 0) {
						bool neW = true;
						for (int i = 0; i < n; i++) {
							if (sum == perimiters[i][0]) {
								perimiters[i][1]++;
								neW = false;
								break;
							}							
						}
						if (neW) {
							perimiters[n][0] = sum;
							perimiters[n][1] = 1;
							n++;
						}
					}
					else {
						perimiters[0][0] = sum;
						perimiters[0][1] = 1;
						n++;
					}
					
				}
			}			
		}
	}
	int max = 0;
	int index;
	for (int i = 0; i < n; i++) {
		if (perimiters[i][1] >max) {
			max = perimiters[i][1];
			index = i;
		}
	}
	cout << perimiters[index][0] << endl;
	
	system("pause");
	return 0;
}