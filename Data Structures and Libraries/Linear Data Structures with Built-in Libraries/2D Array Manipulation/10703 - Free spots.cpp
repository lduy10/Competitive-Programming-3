#include <bits/stdc++.h>

using namespace std;

int main() {
	int w, h, n;
	while (cin >> w >> h >> n) {
		if (w == h && h == n && n == 0) {
			break;
		}
		vector<vector<int>> b(w + 1, vector<int> (h + 1, 0));
		while (n--) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for (int i = min(x1, x2); i <= max(x1, x2); i++) {
				for (int j = min(y1, y2); j <= max(y1, y2); j++) {
					b[i][j]++;
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= w; i++) {
			for (int j = 1; j <= h; j++) {
				if (!b[i][j]) {
					ans++;
				}
			}
		}
		cout << "There ";
		if (ans < 2) {
			cout << "is ";
			if (ans == 0) {
				cout << "no ";
			} else {
				cout << "one ";
			}
		} else {
			cout << "are " << ans << " ";
		}
		cout << "empty " << "spot";
		if (ans != 1) {
			cout << "s";
		}
		cout << ".\n";
	}
	return 0;
}
