#include <bits/stdc++.h>

using namespace std;

int main() {
	int dx[] = {0, -1, 0, 1};
	int dy[] = {-1, 0, 1, 0};
	int n, r, c, k;
	while (cin >> n >> r >> c >> k, n, r, c, k) {
		int current[r + 1][c + 1], before[r + 1][c + 1];
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				int x;
				cin >> x;
				current[i][j] = x;
				before[i][j] = x;
			}
		}
		while (k--) {
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					int v = before[i][j];
					int u = v - 1;
					if (u == -1) {
						u = n - 1;
					}
					int w = v + 1;
					if (w == n) {
						w == 0;
					}
					for (int l = 0; l < 4; l++) {
						int x1 = i + dx[l];
						int y1 = j + dy[l];
						if (x1 >= 1 && x1 <= r && y1 >= 1 && y1 <= c) {
							if (before[x1][y1] == u) {
								current[i][j] = u;
							}
							if (before[x1][y1] == w) {
								current[x1][y1] = before[i][j];
							}
						}
					}
				}
			}
			for (int i = 1; i <= r; i++) {
				for (int j = 1; j <= c; j++) {
					before[i][j] = current[i][j];
				}
			}
		}
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				if (j > 1) {
					cout  << " ";
				}
				cout << current[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
