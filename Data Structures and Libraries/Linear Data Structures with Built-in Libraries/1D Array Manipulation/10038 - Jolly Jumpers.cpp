#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 1) {
			int x;
			cin >> x;
			cout << "Jolly";
		} else {
			vector <int> s(n + 1), tbl(n + 1);
			for (int i = 0; i < n; i++) {
				cin >> s[i];
			}
			s[n] = s[n - 1] + 1;
			for (int i = 0; i < n; i++) {
				int d = abs(s[i] - s[i + 1]);
				if (d < 1 || d > n - 1) {
					break;
				}
				tbl[d]++;
			}
			bool ok = true;
			for (int i = 1; i < n; i++) {
				if (tbl[i] == 0) {
					ok = false;
				}
			}
			if (ok) {
				cout << "Jolly";
			} else {
				cout << "Not jolly";
			}
		}
		cout << "\n";
	}
	return 0;
}
