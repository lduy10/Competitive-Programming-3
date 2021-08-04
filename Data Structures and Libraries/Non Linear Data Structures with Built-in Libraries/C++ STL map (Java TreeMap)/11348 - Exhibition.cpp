#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, set<int>> friends;
		map<int, int> types;
		for (int i = 1; i <= n; i++) {
			int m;
			cin >> m;
			set<int> stamps;
			for (int j = 0; j < m; j++) {
				int sz = stamps.size();
				int x;
				cin >> x;
				stamps.insert(x);
				if (sz != stamps.size()) {
					types[x]++;
				}
			}
			friends[i] = stamps;
		}
		int nTypes = 0;
		for (auto i = types.begin(); i != types.end(); i++) {
			if (i -> second == 1) {
				nTypes++;
			}
		}
		cout << "Case " << tc++ << ":";
		for (int i = 1; i <= n; i++) {
			double cnt = 0;
			for (auto j = friends[i].begin(); j != friends[i].end(); j++) {
				if (types[*j] == 1) {
					cnt++;
				}
			}
			printf(" %f%%", cnt * 100 / nTypes);
		}
		cout << "\n";
	}
	return 0;
}
