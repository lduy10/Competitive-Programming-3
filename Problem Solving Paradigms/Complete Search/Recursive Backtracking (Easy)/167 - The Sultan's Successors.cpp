#include <bits/stdc++.h>

using namespace std;

int ans;
vector<int> row;
vector<vector<int>> board;

bool place(int r, int c) {
	for (int prev = 0; prev < c; prev++) {
		if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c))) {
			return false;
		}
	}
	return true;
}

int calSum() {
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		sum += board[row[i]][i];
	}
	return sum;
}

void backtrack(int c) {
	if (c == 8) {
		int sum = calSum();
		if (sum > ans) {
			ans = sum;
		}
	}
	for (int r = 0; r < 8; r++) {
		if (place(r, c)) {
			row[c] = r;
			backtrack(c + 1);
		}
	}
}

int main() {
	int k;
	cin >> k;
	while (k--) {
		row.assign(8, 0);
		board.assign(8, vector<int> (8));
		ans = INT_MIN;
		for (auto &i : board) {
			for (auto &j : i) {
				cin >> j;
			}
		}
		backtrack(0);
		printf("%5d\n", ans);
	}
	return 0;
}
