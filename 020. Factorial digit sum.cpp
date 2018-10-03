/*
Simulation of human hand written search for factorial number.
First we are initializating all numbers that are going to create factorial (example 1,2,3,4,5,6...,99,100 for factorial 100)
Then we multiply in loop the next two numbers (1x2 & 3x4 & 5x6) (like the human would do on paper) and so on spliting for each iteration of the loop number of multiplicates by two. 
If yet we have the uneven number of multiplicates, uneven item is added after the multiplication of even numbers. (example: 1x2 & 3x4 ->1x2 & 3x4x5)
After we have completed multiplication of all factors, program prints the searched final factorial number, displays number of digits and sum of its digits.

Created by Mateo Maderic
*/
// Completed on Sat, 16 Sep 2017
#include <iostream>
using namespace std;

int main() {

	int factorial;
	int nMultiplicates;
	int x, z, n1, n2, v, r, q, w, s, p, n, m;
	int sum;
	do {
		cout << "Enter desired factorial value: " << flush;
		cin >> factorial;

		//initialization of main array
		int ** umnosci = new int*[factorial];
		for (int i = 0; i < factorial; i++) {
			umnosci[i] = new int[factorial * 4];
		}

		//initialization of first items
		nMultiplicates = factorial;
		z = 1;
		for (int i = 1; i <= nMultiplicates; i++) {
			x = i;
			do {
				if (x < 10) {
					umnosci[i - 1][z] = x;
					z++;
					x = 0;
				}
				else {
					umnosci[i - 1][z] = x % 10;
					z++;
					x /= 10;
				}
			} while (x > 0);
			umnosci[i - 1][0] = z - 1;
			z = 1;
		}
		//start of the main loop
		int **tmp;
		int ***TMP;
		int *extra;
		int **extraTmp;
		int*tmpu;
		s = 1;
		do {
			sum = 0;
			//initialization of temporary array for swaping values
			if (nMultiplicates > 0) {
				tmp = new int*[nMultiplicates];
				for (int i = 0; i < nMultiplicates; i++) {
					tmp[i] = new int[factorial*s];
				}

				//swaping values
				for (int i = 0; i < nMultiplicates; i++) {
					tmp[i][0] = umnosci[i][0];
					for (int j = 1; j <= umnosci[i][0]; j++) {
						tmp[i][j] = umnosci[i][umnosci[i][0] - j + 1];
					}
				}

				for (int i = 0; i < nMultiplicates; i++) {
					for (int j = 0; j <= umnosci[i][0]; j++) {
						umnosci[i][j] = tmp[i][j];
					}
				}
			}
			//check if it is last number (factorial we are searching for)
			if (nMultiplicates == 1) {
				cout << endl << "Factorial of number " << factorial << " is:" << endl;
				for (int i = 1; i <= umnosci[0][0]; i++) {
					cout << umnosci[0][i];
					sum += umnosci[0][i];
				}
				cout << endl << endl << "number of digits: " << umnosci[0][0] << endl;
				cout << "sum of all digits: " <<sum << flush;
				break;
			}
			//delete temporary array for swaping
			for (int i = 0; i < nMultiplicates; i++) {
				delete[] tmp[i];
			}
			delete[]tmp;

			//if the number is not divisible by two
			if (nMultiplicates % 2 != 0) {
				nMultiplicates--;
				extra = new int[umnosci[nMultiplicates][0] + 1];
				for (int i = 0; i < umnosci[nMultiplicates][0] + 1; i++) {
					extra[i] = umnosci[nMultiplicates][i];
					p = 1;
				}
			}
			else {
				p = 0;
			}

			//initialization of temporary array for multiplicating items
			TMP = new int**[(nMultiplicates / 2)];
			for (int i = 0; i < (nMultiplicates / 2); i++) {
				TMP[i] = new int*[umnosci[i + i + 1][0] + 1];
				for (int j = 0; j < umnosci[i + i + 1][0] + 1; j++) {
					TMP[i][j] = new int[factorial*s];
					for (int k = 0; k < factorial*s; k++) {
						TMP[i][j][k] = NULL;
					}
				}
			}
			//multiplication
			r = 0;
			for (int i = 0; i < nMultiplicates; i++) {
				v = 1, q = 0;
				n1 = umnosci[i + 1][0];
				n2 = umnosci[i][0];
				TMP[r][0][0] = n1;
				for (int j = 1; j <= n1; j++) {
					z = 1 + q;
					q = 0;
					for (int k = 0; k < n2; k++) {
						x += umnosci[i + 1][umnosci[i + 1][0] - j + 1] * umnosci[i][umnosci[i][0] - k];
						if (x < 10) {
							TMP[r][v][z] = x;
							z++;
							x = 0;
						}
						else {
							TMP[r][v][z] = x % 10;
							z++;
							x /= 10;
						}

					}
					if (x > 0) {
						TMP[r][v][z] = x;
						z++;
						x = 0;
					}
					TMP[r][v][0] = z - 1;
					v++;
					z = 1;
					if (v <= n1) {
						for (int i = 1; i < v; i++) {
							TMP[r][v][z] = 0;
							z++;
							q++;
						}
					}
				}
				i++;
				r++;
			}

			//adding
			w = 0;
			for (int i = 0; i < r; i++) {
				z = 1;
				x = 0;
				for (int j = 0; j < TMP[i][TMP[i][0][0]][0]; j++) {
					for (int k = 0; k < TMP[i][0][0]; k++) {
						x += TMP[i][k + 1][j + 1];
					}
					if (x < 10) {
						umnosci[w][z] = x;
						z++;
						x = 0;
					}
					else {
						umnosci[w][z] = x % 10;
						z++;
						x /= 10;
					}
				}
				if (x > 0) {
					umnosci[w][z] = x;
					z++;
				}
				umnosci[w][0] = z - 1;
				w++;
			}

			//adding extra number( example if we are searching for factorial of 5, first we multiplicated 1x2 & 3x4 and then adding this 
			//extra number would be 3x4x5 (extra)
			if (p == 1) {
				w--;
				x = 0;
				q = 0;
				n1 = umnosci[w][0];
				n2 = extra[0];
				if (n1 > n2) {
					q = n1;
				}
				else {
					q = n2;
				}
				extraTmp = new int*[n1 + 1];
				for (int i = 0; i < n1 + 1; i++) {
					extraTmp[i] = new int[q * 2];
					for (int j = 0; j < q * 2; j++) {
						extraTmp[i][j] = NULL;
					}
				}
				n = 0;	
				tmpu = new int[umnosci[w][0] + 1];
				for (int i = 1; i <= umnosci[w][0]; i++) {
					tmpu[i] = umnosci[w][umnosci[w][0] - i + 1];
				}
				tmpu[0] = umnosci[w][0];

				//multiplicating extra number with last item
				for (n = 1; n <= n1; n++) {
					z = 1;
					for (int i = 1; i < n; i++) {
						extraTmp[n][z] = 0;
						z++;
					}
					for (int j = 1; j <= n2; j++) {
						x += tmpu[tmpu[0] - n + 1] * extra[extra[0] - j + 1];
						if (x < 10) {
							extraTmp[n][z] = x;
							z++;
							x = 0;
						}
						else {
							extraTmp[n][z] = x % 10;
							z++;
							x /= 10;
						}						
					}
					extraTmp[n][0] = z - 1;
					if (x > 0) {
						extraTmp[n][z] = x;
						z++;
						extraTmp[n][0] = z - 1;
						x = 0;
					}
				}				
				n--;
				extraTmp[0][0] = n;
				//adding extra item
				z = 1;
				for (int i = 1; i <= extraTmp[extraTmp[0][0]][0]; i++) {
					for (int j = 1; j <= extraTmp[0][0]; j++) {
						x += extraTmp[j][i];
					}
					if (x < 10) {
						umnosci[w][z] = x;
						x = 0;
						z++;
					}
					else {
						umnosci[w][z] = x % 10;
						x /= 10;
						z++;
					}
				}
				if (x > 0) {
					umnosci[w][z] = x;
					x = 0;
					z++;
				}
				umnosci[w][0] = z - 1;
				w++;
			}
			//deleting temporary arrays
			for (int i = 0; i < r; i++) {
				for (int j = 1; j <= TMP[i][0][0]; j++) {
					delete[]TMP[i][j];
				}
				delete[]TMP[i][0];
				delete[]TMP[i];
			}
			delete[]TMP;
			if (p == 1) {
				delete[]extra;
				delete[]tmpu;
				for (int i = 0; i < n1 + 1; i++) {
					delete[]extraTmp[i];
				}
				delete[]extraTmp;
			}

			nMultiplicates = w;
			s++;
		} while (w > 0);
		cout << endl << endl;
	}while (true);

	return 0;
}