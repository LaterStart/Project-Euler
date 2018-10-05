// Completed on Fri, 5 Jan 2018
#include <iostream>
using namespace std;

int main() {
	const unsigned int limit = 10000;
	int start, m, d, a;
	int x = 0, result = 0;

	for (int i = 2; i <= limit; i++) {
		start = floor(sqrt(i));
		if ((start*start) == i) continue;
		m = 0; d = 1; a = start;
		do {
			m = d * a - m;
			d = (i - (m*m)) / d;
			a = (start + m) / d;
			x++;
		} while (a != 2 * start);
		if (x % 2 == 1)result++;
		x = 0;
	}
	cout << result << endl;
	system("pause");
	return 0;
}