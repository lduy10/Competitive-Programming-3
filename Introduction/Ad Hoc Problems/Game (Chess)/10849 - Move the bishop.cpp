#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int tc, n;
		cin >> tc >> n;
		while (tc--) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 == x2 && y1 == y2) {
				cout << 0;
			} else if ((x1 + y1 - x2 + y2) % 2 != 0) {
				cout << "no move";
			} else if (x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2) {
				cout << 1;
			} else {
				cout << 2;
			}
			cout << "\n";
		}
	}
	return 0;
}
