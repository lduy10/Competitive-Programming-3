#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> sol;
vector<int> row;

bool place(int r, int c) {
	for (int prev = 0; prev < c; prev++) {
		if (row[prev] == r || (abs(row[prev] - r) == abs(prev - c))) {
			return false;
		}
	}
	return true;
}

void backtrack(int c) {
	if (c == 8) {
		sol.emplace_back(row);
	}
	for (int r = 0; r < 8; r++) {
		if (place(r, c)) {
			row[c] = r;
			backtrack(c + 1);
		}
	}

}

int main() {
	int tc = 1;
	row.assign(8, 0);
	backtrack(0);
	while (cin >> row[0] >> row[1] >> row[2] >> row[3] >> row[4] >> row[5] >> row[6] >> row[7]) {
		for (auto &i : row) {
			i--;
		}
		int ans = INT_MAX;
		for (auto &v : sol) {
			int cnt = 0;
			for (int i = 0; i < 8; i++) {
				if (row[i] != v[i])  {
					cnt++;
				}
			}
			if (cnt < ans) ans = cnt;
		}
		cout << "Case " << tc++ << ": " << ans << "\n";
	}
	return 0;
}
