/*    1 Jan 1900 was a Monday.
    Thirty days has September,
    April, June and November.
    All the rest have thirty-one,
    Saving February alone,
    Which has twenty-eight, rain or shine.
    And on leap years, twenty-nine.
    A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.

How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?*/
// Completed on Mon, 11 Sep 2017
#include <iostream>
using namespace std;

int * leapYears;
int leapCount = 0;

bool leapYear(int year) {
	for (int i = 0; i < leapCount; i++) {
		if (year == leapYears[i]) {
			return true;
		}
	}
	return false;
}
int numberDays(int year, int month) {
	int extraDay = 0;
	if (leapYear(year)) {
		extraDay = 1;
	}
	if (month == 3 || month == 5 || month == 8 || month == 10)
	{
		return 30;
	}
	else {
		if (month == 1) {
			return 28 + extraDay;
		}
		return 31;
	}
}
int main() {
	for (int i = 1900; i <= 2000; i++) {
		if (i % 4 == 0) {
			if (i % 100 == 0) {
				if (i % 400 == 0) {
					leapCount++;
				}
			}
			if (i % 100 != 0) {
				leapCount++;
			}
		}
	}
	leapYears = new int[leapCount];
	leapCount = 0;
	int index = 0;
	for (int i = 1900; i <= 2000; i++) {
		if (i % 4 == 0) {
			if (i % 100 == 0) {
				if (i % 400 == 0) {
					leapYears[leapCount] = index;
					leapCount++;
				}
			}
			if (i % 100 != 0) {
				leapYears[leapCount] = index;
				leapCount++;
			}
		}
		index++;
	}

	int *** polje = new int **[101];
	int DAY = 1;
	int COUNTER = 0;
	for (int i = 0; i <= 100; i++) {
		polje[i] = new int*[12];
		for (int j = 0; j < 12; j++) {
			polje[i][j] = new int[numberDays(i,j)];
			for (int k=0; k < numberDays(i, j); k++) {
				polje[i][j][k] = DAY;
				if (i > 0 && k==0 && DAY == 7) {
					COUNTER++;
				}
				DAY++;
				if (DAY == 8) {
					DAY = 1;
				}
			}
		}
	}
	cout << COUNTER << endl;

	system("pause");
	return 0;
}