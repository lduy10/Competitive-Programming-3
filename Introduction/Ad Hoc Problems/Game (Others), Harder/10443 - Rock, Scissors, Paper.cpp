#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int r, c, n;
		cin >> r >> c >> n;
		vector <vector<char>> before(r + 1, vector<char> (c + 1));
		vector <vector<char>> now(r + 1, vector <char> (c + 1));
		for (int i = 1; i <= r; i++) {
			string row;
			cin >> row;
			for (int j = 0; j < c; j++) {
				before[i][j + 1] = row[j];
				now[i][j + 1] = row[j];
			}
		}
		while (n--) {
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					if (before[i][j] == 'R') {
						if (i - 1 >= 1) {
							if (before[i - 1][j] == 'P') {
								now[i][j] = 'P';
							}
						}
						if (j - 1 >= 1) {
							if (before[i][j - 1] == 'P') {
								now[i][j] = 'P';
							}
						}
						if (i + 1 <= r) {
							if (before[i + 1][j] == 'P') {
								now[i][j] = 'P';
							}
						}
						if (j + 1 <= c) {
							if (before[i][j + 1] == 'P') {
								now[i][j] = 'P';
							}
						}

					} else if (before[i][j] == 'P') {
						if (i - 1 >= 1) {
							if (before[i - 1][j] == 'S') {
								now[i][j] = 'S';
							}
						}
						if (j - 1 >= 1) {
							if (before[i][j - 1] == 'S') {
								now[i][j] = 'S';
							}
						}
						if (i + 1 <= r) {
							if (before[i + 1][j] == 'S') {
								now[i][j] = 'S';
							}
						}
						if (j + 1 <= c) {
							if (before[i][j + 1] == 'S') {
								now[i][j] = 'S';
							}
						}
					} else if (before[i][j] == 'S') {
						if (i - 1 >= 1) {
							if (before[i - 1][j] == 'R') {
								now[i][j] = 'R';
							}
						}
						if (j - 1 >= 1) {
							if (before[i][j - 1] == 'R') {
								now[i][j] = 'R';
							}
						}
						if (i + 1 <= r) {
							if (before[i + 1][j] == 'R') {
								now[i][j] = 'R';
							}
						}
						if (j + 1 <= c) {
							if (before[i][j + 1] == 'R') {
								now[i][j] = 'R';
							}
						}
					}
				}
			}
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					before[i][j] = now[i][j];
				}
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cout << before[i][j];
			}
			cout << "\n";
		}
		
		if (t) {
			cout << "\n";
		}
	}
	return 0;
}
