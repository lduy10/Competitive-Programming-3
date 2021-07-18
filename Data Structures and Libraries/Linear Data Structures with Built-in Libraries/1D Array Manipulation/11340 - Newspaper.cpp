#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int k;
		cin >> k;
		vector<int> tbl(50000, 0);
		for (int i = 0; i < k; i++) {
			char c;
			double v;
			cin >> c >> v;
			tbl[c] = v;
		}
		int m;
		cin >> m;
		double ans = 0;
		cin.ignore();
		while (m--) {
			string s;
			getline(cin, s);
			for (int i = 0; i < s.size(); i++) {
				ans += tbl[s[i]];
			}
		}
		printf("%.2lf$\n", ans / 100);
	}
	return 0;
}
