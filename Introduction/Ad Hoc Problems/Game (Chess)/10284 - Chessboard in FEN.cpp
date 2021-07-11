#include <bits/stdc++.h>

using namespace std;

int main() {
	string r;
	while (cin >> r) {
		int board[9][9];
		for (int i = 1; i <= 8; i ++) {
			for (int j = 1; j <= 8; j++) {
				board[i][j] = 0;
			}
		}
		vector<string> rows(9);


		r += "/";
		string tmp = "";
		int x = 1;
		for (int i = 0; i < r.size(); i++) {
			if (r[i] == '/') {
				rows[x] = tmp;
				x++;
				tmp = "";
			} else {
				tmp += r[i];
			}
		}
		x = 1;
		int c = 1;
		for (int i = 1; i <= 8; i++) {
			for (int j = 0; j < rows[x].size(); j++) {
				if (isalpha(rows[x][j])) {
					board[i][c] = 1;
					c += 1;
				} else {
					c += rows[x][j] - '0';
				}
			}
			x++;
			c = 1;
		}
		x = 1, c = 1;
		for (int i = 1; i <= 8; i++) {
			for (int j = 0; j < rows[x].size(); j++) {
				if (isalpha(rows[x][j])) {
					if (rows[x][j] == 'p') {
						if (i + 1 <= 8) {
							if (c - 1 > 0 && board[i + 1][c - 1] != 1) {
								board[i + 1][c - 1] = 2;
							}
							if (c + 1 < 9 && board[i + 1][c + 1] != 1) {
								board[i + 1][c + 1] = 2;
							}
						}
					} else if (rows[x][j] == 'P') {
						if (i - 1 >= 1) {
							if (c - 1 > 0 && board[i - 1][c - 1] != 1) {
								board[i - 1][c - 1] = 2;
							}
							if (c + 1 < 9 && board[i - 1][c + 1] != 1) {
								board[i - 1][c + 1] = 2;
							}
						}
					} else if (rows[x][j] == 'r' || rows[x][j] == 'R') {
						for (int z = c - 1; z >= 1; z--) {
							if (board[i][z] == 1) {
								break;
							}
							board[i][z] = 2;
						}
						for (int z = c + 1; z <= 8; z++) {
							if (board[i][z] == 1) {
								break;
							}
							board[i][z] = 2;
						}
						for (int z = i - 1; z >= 1; z--) {
							if (board[z][c] == 1) {
								break;
							}
							board[z][c] = 2;
						}
						for (int z = i + 1; z <= 8; z++) {
							if (board[z][c] == 1) {
								break;
							}
							board[z][c] = 2;
						}
					} else if (rows[x][j] == 'n' || rows[x][j] == 'N') {
						if (i - 1 > 0 && c - 2 > 0 && board[i - 1][c - 2] != 1) {
							board[i - 1][c - 2] = 2;
						}
						if (i - 2 > 0 && c - 1 > 0 && board[i - 2][c - 1] != 1) {
							board[i - 2][c - 1] = 2;
						}
						if (i - 2 > 0 && c + 1 < 9 && board[i - 2][c + 1] != 1) {
							board[i - 2][c + 1] = 2;
						}
						if (i - 1 > 0 && c + 2 < 9 && board[i - 1][c + 2] != 1) {
							board[i - 1][c + 2] = 2;
						}
						if (i + 1 < 9 && c + 2 < 9 && board[i + 1][c + 2] != 1) {
							board[i + 1][c + 2] = 2;
						}
						if (i + 2 < 9 && c + 1 < 9 && board[i + 2][c + 1] != 1) {
							board[i + 2][c + 1] = 2;
						}
						if (i + 2 < 9 && c - 1 > 0 && board[i + 2][c - 1] != 1) {
							board[i + 2][c - 1] = 2;
						}
						if (i + 1 < 9 && c - 2 > 0 && board[i + 1][c - 2] != 1) {
							board[i + 1][c - 2] = 2;
						}
					} else if (rows[x][j] == 'k' || rows[x][j] == 'K') {
						if (c - 1 > 0 && board[i][c - 1] != 1) {
							board[i][c - 1] = 2;
						}
						if (i - 1 > 0 && c - 1 > 0 && board[i - 1][c - 1] != 1) {
							board[i - 1][c - 1] = 2;
						}
						if (i - 1 > 0 && board[i - 1][c] != 1) {
							board[i - 1][c] = 2;
						}
						if (i - 1 > 0 && c + 1 < 9 && board[i - 1][c + 1] != 1) {
							board[i - 1][c + 1] = 2;
						}
						if (c + 1 < 9 && board[i][c + 1] != 1) {
							board[i][c + 1] = 2;
						}
						if (i + 1 < 9 && c + 1 < 9 && board[i + 1][c + 1] != 1) {
							board[i + 1][c + 1] = 2;
						}
						if (i + 1 < 9 && board[i + 1][c] != 1) {
							board[i + 1][c] = 2;
						}
						if (i + 1 < 9 && c - 1 > 0 && board[i + 1][c - 1] != 1) {
							board[i + 1][c - 1] = 2;
						}
					} else {
						for (int z = i - 1, y = c - 1; z >= 1 && y >= 1; z--, y--) {
							if (board[z][y] == 1) {
								break;
							}
							board[z][y] = 2;
						}
						for (int z = i - 1, y = c + 1; z >= 1 && y <= 8; z--, y++) {
							if (board[z][y] == 1) {
								break;
							}
							board[z][y] = 2;
						}
						for (int z = i + 1, y = c + 1; z <= 8 && y <= 8; z++, y++) {
							if (board[z][y] == 1) {
								break;
							}
							board[z][y] = 2;
						}
						for (int z = i + 1, y = c - 1; z <= 8 && y >= 1; z++, y--) {
							if (board[z][y] == 1) {
								break;
							}
							board[z][y] = 2;
						}
						if (rows[x][j] == 'q' || rows[x][j] == 'Q') {
							for (int z = c - 1; z >= 1; z--) {
								if (board[i][z] == 1) {
									break;
								}
								board[i][z] = 2;
							}
							for (int z = c + 1; z <= 8; z++) {
								if (board[i][z] == 1) {
									break;
								}
								board[i][z] = 2;
							}
							for (int z = i - 1; z >= 1; z--) {
								if (board[z][c] == 1) {
									break;
								}
								board[z][c] = 2;
							}
							for (int z = i + 1; z <= 8; z++) {
								if (board[z][c] == 1) {
									break;
								}
								board[z][c] = 2;
							}
						}
					}
					c++;
				} else {
					c += rows[x][j] - '0';
				}
			}
			x++;
			c = 1;
		}
		int ans = 0;
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				if (board[i][j] == 0) {
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
