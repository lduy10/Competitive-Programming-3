#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		vector<vector<int>> matrix(n + 1, vector<int>(n + 1));
		vector<bool> row(n + 1, false), col(n + 1, false);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> matrix[i][j];
			}
		}
		int cr = 0, cc = 0;
		for (int i = 1; i <= n; i++) {
			int r = 0, c = 0;
			for (int j = 1; j <= n; j++) {
				if (matrix[i][j] == 1) {
					r++;
				}
				if (matrix[j][i] == 1) {
					c++;
				}
			}
			if (r % 2 == 0) {
				row[i] = true;
			} else {
				cr++;
			}
			if (c % 2 == 0) {
				col[i] = true;
			} else {
				cc++;
			}
		}
		if (cr > 1 || cc > 1 || cr != cc) {
			cout << "Corrupt";
		} else if (cr == 1 && cc == 1) {
			cout << "Change bit " << "(";
			for (int i = 1; i <= n; i++) {
				if (!row[i]) {
					cout << i;
					break;
				}
			}
			cout << ",";
			for (int i = 1; i <= n; i++) {
				if (!col[i]) {
					cout << i;
					break;
				}
			}
			cout << ")";
		} else {
			cout << "OK";
		}
		cout << "\n";
	}
	return 0;
}
