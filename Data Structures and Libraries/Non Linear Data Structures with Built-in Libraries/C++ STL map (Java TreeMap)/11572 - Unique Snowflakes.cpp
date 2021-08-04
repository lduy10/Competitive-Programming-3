#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> s(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
		}
		int ans = 0, cnt = 0;
		map<int, int> pos;
		for (int i = 1; i <= n; i++) {
			int p = pos[s[i]];
			if (!p) {
				pos[s[i]] = i;
				cnt++;
				if (ans < cnt) {
					ans = cnt;
				}
			} else {
				if (ans < cnt) {
					ans = cnt;
				}
				cnt = 0;
				pos[s[i]] = i;
				i = p;
				pos.clear();
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
