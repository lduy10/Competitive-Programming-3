#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> tbl(3651, 0);
		for (int i = 6; i <= n; i += 7) {
			tbl[i]++;
			tbl[i + 1]++;
		}
		int p;
		cin >> p;
		int cnt = 0;
		for (int i = 1; i <= p; i++) {
			int h;
			cin >> h;
			int d = h;
			for (int j = h; j <= n; j += d) {
				if (!tbl[j]) {
					cnt++;
					tbl[j]++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
