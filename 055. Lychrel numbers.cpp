/*If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. 
A number that never forms a palindrome through the reverse and add process is called a Lychrel number. 
Due to the theoretical nature of these numbers, and for the purpose of this problem, we shall assume that a number is Lychrel until proven otherwise. 
In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, (ii) no one,
with all the computing power that exists, has managed so far to map it to a palindrome. 
In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?*/
// Completed on Sat, 14 Oct 2017
#include <iostream>
#include <string>
using namespace std;

string reverse(string n) {
	string tmp;
	for (int i = n.length()-1; i >=0; i--) {
		tmp += n[i];
	}
	return tmp;
}
bool palindrome(string n) {
	bool palindrome = true;
	for (int i = 0; i < n.length() / 2; i++) {
		if (n[i] != n[(n.length() - 1) - i]) {
			palindrome = false;
			break;
		}
	}
	return palindrome;
}
string addStrings(string a, string b) {
	string tmp;
	int x = 0;
	int y = 0;
	for (int i = a.length()-1; i >=0; i--) {
		x += b[i] - '0' + a[i] - '0';
		if (x < 10) {
			tmp.resize(tmp.length()+1, '+');
			tmp[y] = x+'0';
			x = 0;
			y++;
			
		}
		else {
			tmp.resize(tmp.length() + 1, '+');
			tmp[y] = (x % 10) + '0';
			x /= 10;
			y++;
			
		}
	}
	if (x > 0) {
		do {
			if (x < 10) {
				tmp.resize(tmp.length() + 1, '+');
				tmp[y] = x + '0';
				x = 0;				
				y++;
				break;
			}
			else {
				tmp.resize(tmp.length() + 1, '+');
				tmp[y] = (x % 10) + '0';
				x /= 10;
				y++;				
			}
		} while (true);
	}
	return reverse(tmp);
}
int main() {
	string a, b, ab;
	int count;
	int count2 = 0;
	for (int i = 1; i < 10000; i++) {
		ab = to_string(i);
		count = 0;
		do {
			a = ab;
			b = reverse(a);
			ab = addStrings(a, b);
			if (palindrome(ab)) {
				//cout <<i<<" "<<a<<" "<<b<<" "<<ab << endl;
				break;
			}
			count++;
			if (count == 50) {
				count2++;
			}
		} while (count<50);
	}
	cout << count2 << endl;
	system("pause");
	return 0;
}