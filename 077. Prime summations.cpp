// Completed on Wed, 20 Dec 2017
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

unsigned int * SelectCoins(unsigned int value, unsigned int * pointer = nullptr) {
	if (pointer != nullptr) delete[]pointer;
	unsigned int i = 1, count = 0;
	while (primesList[i++] <= value)
		count++;
	unsigned int * coins = new unsigned int[count + 1];
	for (int i = 1; i <= count; i++)
		coins[i] = primesList[i];
	coins[0] = count;
	return coins;
}


unsigned int CoinChangeFunction(unsigned int value, unsigned int* &coins) {
	unsigned int n = coins[0];
	unsigned int * temp = new unsigned int[value + 1]();
	unsigned int coin; temp[0] = 1;
	for (unsigned int i = 1; i <= n; i++) {
		coin = coins[i];
		for (int amount = 0; amount <= value; amount++) {
			if (amount >= coin)temp[amount] += temp[amount - coin];
		}
	}
	coin = temp[value];
	delete[]temp;
	return coin;
}

int main() {
	unsigned int * coins;
	unsigned int combinations;
	sieve();

	for (int i = 1; ; i++) {
		coins = SelectCoins(i);
		combinations = CoinChangeFunction(i, coins);
		if (combinations >= 5000) {
			cout << i << endl;
			system("pause");
		}
	}
	return 0;
}