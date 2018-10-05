// Completed on Tue, 19 Dec 2017
#include <iostream>
#include <iomanip>
using namespace std;

double PermutationRepetition(int n, int k) {
	return pow(n, k);
}

void WritePermutationswithRepetition(int size, int number_of_units, unsigned int * &storage) {
	bool breakme;
	int * control = new int[size]();
	for (int i = 0; i < size; i++) {
		control[i] = 1;
	}
	int position = 0; unsigned int sum; int c = 0;
	do {
		c++;
		sum = 0;
		for (int i = 0; i < size; i++) {
			sum += control[i];
		}
		storage[position] = sum;
		position++;
		breakme = false;
		control[size - 1]++;
		for (int i = size - 1; i >= 0; i--) {
			if (control[0] == number_of_units + 1) {
				breakme = true;
				break;
			}
			if (control[i] == number_of_units + 1) {
				control[i - 1]++;
				control[i] = 1;
			}
		}
		if (breakme) break;
	} while (true);
}

int main() {
	unsigned int a = PermutationRepetition(6, 6);
	unsigned int b = PermutationRepetition(4, 9);
	unsigned long long outcomes = static_cast<unsigned long long>(a)*b;
	cout << a << " " << b << endl;
	cout << "Total outcomes: " << outcomes << endl;

	unsigned int * A = new unsigned int[a];
	unsigned int * B = new unsigned int[b];

	WritePermutationswithRepetition(6, 6, A);
	WritePermutationswithRepetition(9, 4, B);

	int Bp;
	unsigned long long favorable = 0;
	for (int i = 0; i < b; i++) {
		Bp = *(B + i);
		for (int j = 0; j < a; j++) {
			if (Bp > A[j]) favorable++;
		}
	}
	cout << "Total favorable outcomes " << " " << favorable << endl;

	double probability = static_cast<double>(favorable) / static_cast<double>(outcomes);
	cout << setprecision(7) << "Probability: " << probability << endl;

	system("pause");
	return 0;
}