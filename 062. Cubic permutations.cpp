/*
The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.
*/
// Completed on Fri, 24 Nov 2017
#include <iostream>
#include <string>
using namespace std;

int main() {
	unsigned int N = pow(10,4); unsigned int C = 0;
	unsigned long long ** cubes = new unsigned long long*[N]();
	string tmp; 

	//fill cubes information
	cout << "Loading cubes table.." << endl;
	for (unsigned int i = 22; i <= N; i++) {
		cubes[C] = new unsigned long long[5]();
		cubes[C][3] = 1;
		cubes[C][1] = pow(i, 3); //number
		tmp = to_string(cubes[C][1]); 
		cubes[C][0] = tmp.length(); //number of digits
		for (unsigned int j = 0; j < tmp.length(); j++) {
			cubes[C][2] += tmp[j] - '0'; //sum of digits
			if (tmp[j] - '0' != 0) {
				cubes[C][3] *= tmp[j] - '0'; //prime factorization multiplication for possible number identification
			}
		}
		C++;
	}
	cout << "Table loaded with " << C << " cube numbers." << endl << endl;

	//find possible numbers and sort digits
	cout << "Checking for possible solutions.." << endl;
	unsigned int count; int P = 0;
	string mem[5]; unsigned int z;
	string ** possibleCubes = new string*[C];	
	string num; bool changed; char tm;
	for (int i = 0; i < C; i++) {
		mem[0] = to_string(cubes[i][1]); count = 1; z = 1;
		for (int j = 0; j < C; j++) {
			if (i!=j && cubes[i][0] == cubes[j][0] && cubes[i][2] == cubes[j][2] && cubes[i][3] == cubes[j][3]) {
				possibleCubes[P] = new string[2]();
				possibleCubes[P][0] = to_string(cubes[i][1]);
				num = possibleCubes[P][0];
				do {
					changed = false;
					for (int k = 0; k < num.length() - 1; k++) {
						if (num[k + 1] - '0' < num[k] - '0') {
							tm = num[k];
							num[k] = num[k + 1];
							num[k + 1] = tm;
							changed = true;
						}
					}
				} while (changed);
				possibleCubes[P][1] = num;
				P++;
				break;
			}
		}
	}
	cout << "Selected " << P << " numbers for evaluation." << endl << endl;

	//find final solution
	cout << "Searching for final solution..." << endl;
	for (int i = 0; i < P; i++) {
		mem[0] = possibleCubes[i][0]; count = 1; z=1;
		for (int j = i + 1; j < P; j++) {
			if (possibleCubes[i][1] == possibleCubes[j][1] && possibleCubes[i][0].length() == possibleCubes[j][0].length()) {
				if (count < 5) {
					mem[z] = possibleCubes[j][0];
					z++;
				}
				count++;
				if (count > 5) break;
			}
		}
		if (count == 5) {
			cout << "Result: " << endl;
			cout << mem[0] << endl << endl;
			cout << mem[0] << endl;
			cout << mem[1] << endl;
			cout << mem[2] << endl;
			cout << mem[3] << endl;
			cout << mem[4] << endl;
			system("pause");
		}
	}

	cout << "Number not found" << endl;
	system("pause");
	return 0;
}