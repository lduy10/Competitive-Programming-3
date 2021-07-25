#include <bits/stdc++.h>

using namespace std;

int main() {
	int x, tc = 1;
	cin >> x;
	while (x--) {
		int r, c, m, n;
		cin >> r >> c >> m >> n;
		vector<char> rg;
		vector<int> cnt(127, 0);
		int maxcnt = -1;
		for (int i = 0; i < r * c; i++) {
			char a;
			cin >> a;
			if (!cnt[a]) {
				rg.push_back(a);
			}
			cnt[a]++;
			if (maxcnt < cnt[a]) {
				maxcnt = cnt[a];
			}
		}
		int ans = 0;
		for (int i = 0; i < rg.size(); i++) {
			if (cnt[rg[i]] == maxcnt) {
				ans += m * maxcnt;
			} else {
				ans += n * cnt[rg[i]];
			}
		}
		cout << "Case " << tc++ << ": " << ans << "\n";
	}
	return 0;
}
