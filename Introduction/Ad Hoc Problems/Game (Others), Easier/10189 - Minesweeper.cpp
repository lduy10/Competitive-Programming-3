#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, n, tc = 1;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) {
			break;
		}
		if (tc > 1) {
			cout << "\n";
		}
		string board[m + 1][n + 1];
		string row;
		for (int i = 1; i <= m; i++) {
			cin >> row;
			for (int j = 0; j < n; j++) {
				board[i][j + 1] = row[j];
			}
		}

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] != "*") {
					int cnt = 0;
					if (i + 1 <= m && j - 1 >= 1 && board[i + 1][j - 1] == "*") {
						cnt++;
					}
					if (j - 1 >= 1 && board[i][j - 1] == "*") {
						cnt++;
					}
					if (i - 1 >= 1 && j - 1 >= 1 && board[i - 1][j - 1] == "*") {
						cnt++;
					}
					if (i - 1 >= 1 && board[i - 1][j] == "*") {
						cnt++;
					}
					if (i - 1 >= 1 && j + 1 <= n && board[i - 1][j + 1] == "*") {
						cnt++;
					}
					if (j + 1 <= n && board[i][j + 1] == "*") {
						cnt++;
					}
					if (i + 1 <= m && j + 1 <= n && board[i + 1][j + 1] == "*") {
						cnt++;
					}
					if (i + 1 <= m && board[i + 1][j] == "*") {
						cnt++;
					}
					board[i][j] = to_string(cnt);
				}
			}
		}
		
		cout << "Field #" << tc++ <<":\n";
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cout << board[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
