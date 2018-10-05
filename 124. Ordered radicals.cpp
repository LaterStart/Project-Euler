// Completed on Sat, 6 Jan 2018
#include <iostream>
using namespace std;

const unsigned int limit = 1000000;
unsigned int primesList[limit + 1];
bool *primeCheck = new bool[limit + 1]();

void sieve() {
	double root = sqrt(limit);
	for (unsigned long long n = 4; n <= limit; n += 2) {
		primeCheck[n] = true;
	}
	for (unsigned long long n = 3; n <= root; n += 2) {
		if (!primeCheck[n]) {
			for (unsigned long long m = n * n; m <= limit; m += (2 * n)) {
				primeCheck[m] = true;
			}
		}
	}
	unsigned long long count = 0;
	for (unsigned long long i = 2; i <= limit; i++) {
		if (!primeCheck[i]) {
			primesList[++count] = i;
		}
	}
	primesList[0] = count;
}


int Radical(int n) {
	unsigned int r = 1;
	for (unsigned int i = 1; i <= primesList[0]; i++) {
		if (n % primesList[i] == 0) {
			r *= primesList[i];
			while (n % primesList[i] == 0) {
				n /= primesList[i];
			}
		}
		if (n == 1) return r;
	}
}

template <class Type>
void Swap(Type &first, Type &second) {
	Type temp = first;
	first = second;
	second = temp;
}

int partition(int** &arr, int low, int high, int index)
{
	int pivot = arr[high][index];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j][index] <= pivot)
		{
			i++;
			Swap(arr[i], arr[j]);
		}
	}
	Swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void QuickSort(int** &arr, int low, int high, int index)
{
	if (low < high)
	{
		int pi = partition(arr, low, high, index);

		QuickSort(arr, low, pi - 1, index);
		QuickSort(arr, pi + 1, high, index);
	}
}

int main() {
	sieve(); int r = 0;
	int ** radicals = new int*[limit];
	for (int i = 1; i <= limit; i++) {
		radicals[r] = new int[2];
		radicals[r][0] = i;
		radicals[r++][1] = Radical(i);
	}
	QuickSort(radicals, 0, limit - 1, 1);
	bool changed;
	do {
		changed = false;
		for (int i = 0; i < limit - 1; i++) {
			if (radicals[i + 1][1] == radicals[i][1] && radicals[i + 1][0] < radicals[i][0]) {
				Swap(radicals[i + 1], radicals[i]);
				changed = true;
			}
		}
	} while (changed);

	cout << radicals[9999][0] << endl;

	system("pause");
	return 0;
}