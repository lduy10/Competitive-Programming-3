#include <bits/stdc++.h>

using namespace std;

int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, -1, 0, 1};

int main() {
	int r, c, n, tc = 1;
	while (cin >> r >> c >> n) {
		if (r == c && c == n && n == 0) {
			break;
		}
		bitset<10000> rows;
		bitset<10000> cols;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			rows[x] = 1;
			cols[y] = 1;
		}
		int x0, y0;
		cin >> x0 >> y0;
		bool escapable = false;
		for (int i = 0; i < 5; i++) {
			int x1 = x0 + dx[i];
			int y1 = y0 + dy[i];
			if (x1 >= 0 && x1 < r && y1 >= 0 && y1 < c && rows[x1] == 0 && cols[y1] == 0) {
				escapable = true;
				break;
			}
		}
		cout << "Case " << tc++ << ": ";
		if (escapable) {
			cout << "Escaped again! More 2D grid problems!";
		} else {
			cout << "Party time! Let's find a restaurant!";
		}
		cout << "\n";
	}
	return 0;
}
