/* Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.
How many such routes are there through a 20×20 grid?

For all other nodes, the value is the sum of its top and left neighbors

*/
// Completed on Fri, 18 Aug 2017
#include <iostream>
using namespace std;

int main() {

	int64_t gridSize;
	cout << "Enter grid size: (For 20x20 you should enter 20)"<<endl;
	cin >> gridSize;
	gridSize = gridSize + 1;

	int64_t ** polje = new int64_t*[gridSize];

	for (int i = 0; i < gridSize; i++) {
		polje[i] = new int64_t[gridSize];
	}

	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < gridSize; j++) {
			if (i == 0 || j == 0) {
				polje[i][j] = 1;
			}
			else {
				polje[i][j] = polje[i - 1][j] + polje[i][j - 1];
			}
		}
	}
	gridSize = gridSize - 1;

	cout << polje[gridSize][gridSize] << endl;

	system("pause");
	return 0;
}