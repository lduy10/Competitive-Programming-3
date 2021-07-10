#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		vector <int> A(4), B(3), cards(69);
		cin >> A[1] >> A[2] >> A[3] >> B[1] >> B[2]; 
		if (A[1] == A[2] && A[2] == A[3] && A[3] == B[1] && B[1] == B[2] && B[2] == 0) {
			break;
		}
		cards[A[1]] = 1;
		cards[A[2]] = 1;
		cards[A[3]] = 1;
		cards[B[1]] = 1;
		cards[B[2]] = 1;
		sort(A.begin() + 1, A.end());
		sort(B.begin() + 1, B.end());
		int card = 53;
		cout << "Sap xep:\n";

		for (int i = 1; i <= 3; i++) {
			cout << A[i] << " ";
		}
		cout << "\n";
		for (int i = 1; i <= 3; i++) {
			cout << B[i] << " ";
		}
		if (B[1] > A[3]) {
			for (int i = 1; i <= 52 && i < card; i++) {
				if (cards[i] == 0) {
					card = i;
				}
			}
		}
		cout << "\nTurn 1: " << card << "\n";
		if (B[2] > A[3]) {
			for (int i = A[3] + 1; i <= 52 && i < card; i++) {
				if (cards[i] == 0) {
					card = i;
				}
			}
		}
		cout << "Turn 2: " << card << "\n";
		if (B[1] > A[2]) {
			for (int i = A[2] + 1; i <= 52 && i < card; i++) {
				if (cards[i] == 0) {
					card = i;
				}
			}
		}
		cout << "Turn 3: " << card << "\n";
		if (card == 53) {
			cout << -1 << "\n";
		} else {
			cout << card << "\n";
		}
		
	}
	return 0;
}
