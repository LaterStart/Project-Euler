//projecteuler.net/problem=54
// Completed on Thu, 26 Oct 2017
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int cards[5];
int *cards1 = new int[5];
int *cards2 = new int[5];
int evaluate(string hand) {
	int value;
	int ns[15] = {NULL};
	int D = 0, C = 0, H = 0, S = 0;
	int n = 0;
	bool swap;
	for (int i = 0; i < hand.length(); i++) {
		if (hand[i] == 'T') {
			ns[10]++;
			cards[n] = 10;
			n++;
		}
		else if (hand[i] == 'J') {
			ns[11]++;
			cards[n] = 11;
			n++;
		}
		else if (hand[i] == 'Q') {
			ns[12]++;
			cards[n] = 12;
			n++;
		}
		else if (hand[i] == 'K') {
			ns[13]++;
			cards[n] = 13;
			n++;
		}
		else if (hand[i] == 'A') {
			ns[14]++;
			cards[n] = 14;
			n++;
		}
		else if (hand[i] == 'D') {
			D++;
		}
		else if (hand[i] == 'C') {
			C++;
		}
		else if (hand[i] == 'H') {
			H++;
		}
		else if (hand[i] == 'S') {
			S++;
		}
		else if (hand[i] == '2') {
			ns[2]++;
			cards[n] = 2;
			n++;
		}
		else if (hand[i] == '3') {
			ns[3]++;
			cards[n] = 3;
			n++;
		}
		else if (hand[i] == '4') {
			ns[4]++;
			cards[n] = 4;
			n++;
		}
		else if (hand[i] == '5') {
			ns[5]++;
			cards[n] = 5;
			n++;
		}
		else if (hand[i] == '6') {
			ns[6]++;
			cards[n] = 6;
			n++;
		}
		else if (hand[i] == '7') {
			ns[7]++;
			cards[n] = 7;
			n++;
		}
		else if (hand[i] == '8') {
			ns[8]++;
			cards[n] = 8;
			n++;
		}
		else if (hand[i] == '9') {
			ns[9]++;
			cards[n] = 9;
			n++;
		}
	}
	//Royal Flush
	if (ns[10]= 1 && ns[11] == 1 && ns[12] == 1 && ns[13] == 1 && ns[14] == 1) {
		if (D == 5 || C == 5 || H == 5 || S == 5) {
			value = 1000;
			return value;
		}
		//Highest straight
		else {
			value = 514;
			return value;
		}
	}
	//sort cards by value
	int tmp;
	do {
		swap = false;
		for (int j = 0; j < 4; j++) {
			if (cards[j + 1] < cards[j]) {
				tmp = cards[j];
				cards[j] = cards[j + 1];
				cards[j + 1] = tmp;
				swap = true;
			}
		}
	} while (swap);
	//check if straight
	bool straight = true;
	for (int j = 4; j >0; j--) {
		if (cards[j] - cards[j - 1] != 1) {
			straight = false;
			break;
		}
	}	
	int max = 0;
	//Straight Flush
	if (D == 5 || C == 5 || H == 5 || S == 5) {
		if (straight) {
			value = 900;
			for (int i = 0; i < 5; i++) {
				if (cards[i] > max) {
					max = cards[i];
				}
			}
			value += max;
			return value;
		}
		//Flush
		else {
			value = 600;
			for (int i = 0; i < 5; i++) {
				if (cards[i] > max) {
					max = cards[i];
				}
			}
			value += max;
			return value;
		}
	}
	//Four of a kind
	if (ns[2] == 4 || ns[3] == 4 ||ns[4]==4|| ns[5] == 4 || ns[6] == 4 || ns[7] == 4 || ns[8] == 4 || ns[9] == 4 || ns[10] == 4 || ns[11] == 4 || ns[12] == 4 || ns[13] == 4 || ns[14] == 4) {
		value = 800;
		for (int i = 2; i <= 14;i++) {
			if (ns[i] == 4) {
				value += i;
				break;
			}
		}
		return value;
	}
	//Full house
	if (ns[2] == 3 || ns[3] == 3 || ns[4] == 3 || ns[5] == 3 || ns[6] == 3 || ns[7] == 3 || ns[8] == 3 || ns[9] == 3 || ns[10] == 3 || ns[11] == 3 || ns[12] == 3 || ns[13] == 3 || ns[14] == 3) {
		if (ns[2] == 2 || ns[3] == 2 || ns[4] == 2 || ns[5] == 2 || ns[6] == 2 || ns[7] == 2 || ns[8] == 2 || ns[9] == 2 || ns[10] == 2 || ns[11] == 2 || ns[12] == 2 || ns[13] == 2 || ns[14] == 2) {
			value = 700;
			for (int i = 2; i <= 14; i++) {
				if (ns[i] == 3) {
					value += i;
					break;
				}
			}
			return value;
		}
		//Three of a kind
		else {
			value = 400;
			for (int i = 2; i <= 14; i++) {
				if (ns[i] == 3) {
					value += i;
					break;
				}
			}
			return value;
		}
	}
	max = 0;
	//straight
	if (straight) {
		value = 500;
		for (int i = 0; i < 5; i++) {
			if (cards[i] > max) {
				max = cards[i];
			}
		}
		value += max;
		return value;
	}
	//Check number of pairs
	int cnt = 0;
	int mem1, mem2;
	for (int j = 0; j < 4; j++) {
		if (cards[j] == cards[j + 1]) {
			cnt++;
			if (cnt == 1) {
				mem1 = cards[j];
			}
			if (cnt == 2) {
				mem2 = cards[j];
			}
		}
	}
	//Two pairs
	if (cnt == 2) {
		value = 300;
		if (mem1 > mem2) {
			value += mem1;
		}
		else {
			value += mem2;
		}
		return value;
	}
	//One pair
	else if (cnt == 1) {
		value = 200;
		value += mem1;
		return value;
	}
	max = 0;
	//High card
	for (int j = 0; j < 5; j++) {
		if (cards[j] > max) {
			max = cards[j];
		}
	}
	value = max;
	return value;
}

int highCard(int * cards, int exclude) {
	int max = 0;
	for (int i = 0; i < 5; i++) {
		if (cards[i] == exclude) {
			cards[i] = NULL;
		}
		if (cards[i] > max) {
			max = cards[i];
		}
	}
	return max;
}

int main() {
	ifstream read;
	string hands[1000];
	int n = 0;
	int player1, player2;
	int win = 0;	
	string hand1, hand2;
	read.open("poker.txt");
	if (read.is_open()) {
		string hand;
		string tmp;
		int cnt = 0;
		int exclude;
		do {
			if (cnt == 5) {
				player1 = evaluate(hand);
				hand1 = hand;
				//cout << hand1 << " ";
				for (int j = 0; j < 5; j++) {
					cards1[j] = cards[j];
				}
				hand = "";
			}
			if (cnt == 10) {
				cnt = 0;
				hand2 = hand;
				//cout << hand2 << endl;
				player2 = evaluate(hand);
				/*for (int i = 0; i < 5; i++) {
					cout << cards1[i] << " ";
				}
				cout << " ";*/
				for (int j = 0; j < 5; j++) {
					cards2[j] = cards[j];
				}
				/*for (int i = 0; i < 5; i++) {
					cout << cards2[i] << " ";
				}
				cout << endl;*/
				cout << player1 << " " << player2 << endl;
				if (player1 > player2) {
					win++;
				}
				else if (player1 == player2) {
					exclude = 0;
					do {
						player1 = highCard(cards1,exclude);
						player2 = highCard(cards2,exclude);
						//cout << player1 << " " << player2 << endl;
						if (player1 > player2) {
							win++;
							break;
						}
						else if (player2 > player1) {
							break;
						}
						exclude = player1;
						if (exclude == 0) {
							break;
						}
					} while (true);
				}
				hand = "";
				cout << win << endl;
			}
			read >> tmp;
			hand += tmp;
			cnt++;			
		} while (!read.eof());
	}
	read.close();

	system("pause");
	return 0;
}