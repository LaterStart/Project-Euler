/*
The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime.
For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
*/
// Completed on Tue, 28 Nov 2017
#include <iostream>
#include <string>
using namespace std;

int primesList[10000]; int P = 1;
void generatePrimelist() {
	primesList[0] = 2;
	bool prime;
	for (unsigned long n = 3; n <= 10000; n += 2) {
		prime = true;
		for (int j = 2; j <= sqrt(n); j++) {
			if (n % j == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			primesList[P] = n; P++;			
		}
	}
}

bool prime;
bool isPrime(unsigned long long n) {
	prime = true;
	for (unsigned long long j = 2; j <= sqrt(n); j++) {
		if (n%j == 0) {
			prime = false;
			break;
		}
	}
	return prime;
}

int main() {
	string tmp;
	generatePrimelist();
	int sum;
	for (int i = 0; i < P; i++) {
		for (int j = i + 1; j < P; j++) {
			tmp = to_string(primesList[i]) + to_string(primesList[j]);
			if (isPrime(stoull(tmp))) {
				tmp = to_string(primesList[j]) + to_string(primesList[i]);
				if (isPrime(stoull(tmp))) {
					for (int k = j + 1; k < P; k++) {
						tmp = to_string(primesList[i]) + to_string(primesList[k]);
						if (isPrime(stoull(tmp))) {
							tmp = to_string(primesList[j]) + to_string(primesList[k]);
							if (isPrime(stoull(tmp))) {
								tmp = to_string(primesList[k]) + to_string(primesList[i]);
								if (isPrime(stoull(tmp))) {
									tmp = to_string(primesList[k]) + to_string(primesList[j]);
									if (isPrime(stoull(tmp))) {
										for (int m = k + 1; m < P; m++) {
											tmp = to_string(primesList[i]) + to_string(primesList[m]);
											if (isPrime(stoull(tmp))) {
												tmp = to_string(primesList[m]) + to_string(primesList[i]);
												if (isPrime(stoull(tmp))) {
													tmp = to_string(primesList[j]) + to_string(primesList[m]);
													if (isPrime(stoull(tmp))) {
														tmp = to_string(primesList[m]) + to_string(primesList[j]);
														if (isPrime(stoull(tmp))) {
															tmp = to_string(primesList[k]) + to_string(primesList[m]);
															if (isPrime(stoull(tmp))) {
																tmp = to_string(primesList[m]) + to_string(primesList[k]);
																if (isPrime(stoull(tmp))) {
																	for (int n = m + 1; n < P; n++) {
																		tmp = to_string(primesList[i]) + to_string(primesList[n]);
																		if (isPrime(stoull(tmp))) {
																			tmp = to_string(primesList[n]) + to_string(primesList[i]);
																			if (isPrime(stoull(tmp))) {
																				tmp = to_string(primesList[j]) + to_string(primesList[n]);
																				if (isPrime(stoull(tmp))) {
																					tmp = to_string(primesList[n]) + to_string(primesList[j]);
																					if (isPrime(stoull(tmp))) {
																						tmp = to_string(primesList[k]) + to_string(primesList[n]);
																						if (isPrime(stoull(tmp))) {
																							tmp = to_string(primesList[n]) + to_string(primesList[k]);
																							if (isPrime(stoull(tmp))) {
																								tmp = to_string(primesList[m]) + to_string(primesList[n]);
																								if (isPrime(stoull(tmp))) {
																									tmp = to_string(primesList[n]) + to_string(primesList[m]);
																									if (isPrime(stoull(tmp))) {
																										cout << primesList[i] << " " << primesList[j] << " " << primesList[k] << " " << primesList[m] <<" "<<primesList[n]<< endl;
																										sum = primesList[i] + primesList[j] + primesList[k] + primesList[m] + primesList[n];
																										cout << sum << endl;
																										system("pause");
																									}
																								}
																							}
																						}
																					}
																				}
																			}
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}						
					}
				}
			}
		}
	}

	system("pause");
	return 0;
}