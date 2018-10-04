/*
A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically,
we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
*/
// Completed on Mon, 18 Sep 2017
#include <iostream>
using namespace std;

int main() {
	int perm = 0;

	for (int a = 0; a < 10; a++) {
		for (int b = 0; b < 10; b++) {
			for (int c = 0; c < 10; c++) {
				for (int d = 0; d < 10; d++) {
					for (int e = 0; e < 10; e++) {
						for (int f = 0; f < 10; f++) {
							for (int g = 0; g < 10; g++) {
								for (int h = 0; h < 10; h++) {
									for (int i = 0; i < 10; i++) {
										for (int j = 0; j < 10; j++) {
											if (a != b && a != c && a != d && a != e && a != f && a != g && a != h && a != i && a != j
												&& b != c && b != d && b != e && b != f && b != g && b != h && b != i && b != j
												&& c != d && c != e && c != f && c != g && c != h && c != i && c != j
												&& d != e && d != f && d != g && d != h && d != i && d != j
												&& e != f && e != g && e != h && e != i && e != j
												&& f != g && f != h && f != i && f != j
												&& g != h && g != i && g != j
												&& h != i && h != j
												&& i != j) {
												perm++;
												cout << a << b << c << d << e << f << g << h << i << j << endl;
												if (perm == 1000000) {
													cout << a << b << c << d << e << f << g << h << i << j << endl;
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