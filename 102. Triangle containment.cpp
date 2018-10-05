/*
Three distinct points are plotted at random on a Cartesian plane, for which -1000 ? x, y ? 1000, such that a triangle is formed.

Consider the following two triangles:

A(-340,495), B(-153,-910), C(835,-947)

X(-175,41), Y(-421,-714), Z(574,-645)

It can be verified that triangle ABC contains the origin, whereas triangle XYZ does not.

Using triangles.txt (right click and 'Save Link/Target As...'), a 27K text file containing the co-ordinates of one thousand "random" triangles, 
find the number of triangles for which the interior contains the origin.

NOTE: The first two examples in the file represent the triangles in the example given above.
*/
// Completed on Fri, 23 Feb 2018
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//triangle area
float area(int x1, int y1, int x2, int y2, int x3, int y3){
	return abs( (x1*(y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);
}

//barycentric coordinates
int main() {
	ifstream read;
	int x = 0, y = 0;
	int x1, x2, x3, y1, y2, y3, i = 0, c = 0;
	string coordinates[6];
	read.open("triangles.txt");
	if (read.is_open()) {
		do {
			read >> coordinates[i++];
			if (i == 6) {
				i = 0;
				x1 = stoi(coordinates[0]);
				y1 = stoi(coordinates[1]);
				x2 = stoi(coordinates[2]);
				y2 = stoi(coordinates[3]);
				x3 = stoi(coordinates[4]);
				y3 = stoi(coordinates[5]);

				/* Calculate area of triangle ABC */
				float A = area(x1, y1, x2, y2, x3, y3);

				/* Calculate area of triangle PBC */
				float A1 = area(x, y, x2, y2, x3, y3);

				/* Calculate area of triangle PAC */
				float A2 = area(x1, y1, x, y, x3, y3);

				/* Calculate area of triangle PAB */
				float A3 = area(x1, y1, x2, y2, x, y);

				/* Check if sum of A1, A2 and A3 is same as A */
				if (A == (A1 + A2 + A3))
					c++;
			}

		} while (!read.eof());
	}
	cout << c << endl;
	system("pause");
	return 0;
}