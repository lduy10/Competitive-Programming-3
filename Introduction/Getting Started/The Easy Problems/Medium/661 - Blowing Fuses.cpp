#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc = 1;
	while (true) {
		int n, m, c;
		cin >> n >> m >> c;
		if (n == m && m == c && c == 0) break;
		vector <pair<int, int>> devices(n + 1);
		int max = -1, sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> devices[i].first;
		}
		for (int i = 1; i <= m; i++) {
			int x;
			cin >> x;
			if (sum != -69) {
				if (devices[x].second) {
					sum -= devices[x].first;
					devices[x].second = 0;
				} else {
					sum += devices[x].first;
					devices[x].second = 1;
				}
				if (sum > c) sum = -69;
				else if (sum > max) max = sum;
			}
		}
		cout << "Sequence " << tc++ << "\n";
		if (sum != -69) {
			cout << "Fuse was not blown.\nMaximal power consumption was " << max << " amperes.\n";
		} else {
			cout << "Fuse was blown.\n";
		}
		cout << "\n";
	}
	return 0;
}
