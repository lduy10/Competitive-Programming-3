#include <bits/stdc++.h>

using namespace std;

int a, b, cnt;
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
	if (c == 8 && row[b] == a) {
		printf("%2d     ", cnt++);
		for (auto &i : row) {
			cout << " " << i + 1;
		}
		cout << "\n";
	}
	for (int r = 0; r < 8; r++) {
		if (place(r, c)) {
			row[c] = r;
			backtrack(c + 1);
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		a--, b--;
		cnt = 1;
		row.assign(8, 0);
		cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
		backtrack(0);
		if (t) {
			cout << "\n";
		}
	}

	return 0;
}
