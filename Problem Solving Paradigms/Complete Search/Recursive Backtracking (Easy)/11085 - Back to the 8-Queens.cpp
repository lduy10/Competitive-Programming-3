#include <bits/stdc++.h>

using namespace std;

vector<int> row, newRow;
int ans;

bool place(int r, int c) {
	for (int prev = 0; prev < c; prev++) {
		if (newRow[prev] == r || (abs(newRow[prev] - r) == abs(prev - c))) {
			return false;
		}
	}
	return true;
}

void backtrack(int c) {
	if (c == 8) {
		int cnt = 0;
		for (int i = 0; i < 8; i++) {
			if (row[i] != newRow[i]) {
				cnt++;
			}
		}
		if (cnt < ans) {
			ans = cnt;
		}
	}
	for (int r = 0; r < 8; r++) {
		if (place(r, c)) {
			newRow[c] = r;
			backtrack(c + 1);
		}
	}

}

int main() {
	int tc = 1;
	row.assign(8, 0);
	while (cin >> row[0] >> row[1] >> row[2] >> row[3] >> row[4] >> row[5] >> row[6] >> row[7]) {
		for (auto &i : row) {
			i--;
		}
		newRow.assign(8, 0);
		ans = INT_MAX;
		backtrack(0);
		cout << "Case " << tc++ << ": " << ans << "\n";
	}
	return 0;
}
