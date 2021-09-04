#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, tc = 0;
	while (cin >> n) {
		pair<int, int> ans;
		map<int, int> m;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			m[x]++;
		}
		int c;
		cin >> c;
		for (auto &i : m) {
			int d = c - i.first;
			if (d < i.first) break;
			if (d == i.first && i.second == 1) continue;
			if (m[d]) ans.first = i.first, ans.second = d;
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n", ans.first, ans.second);
	}
	return 0;
}
