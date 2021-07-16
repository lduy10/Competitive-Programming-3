#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		cin.ignore();
		vector<int> nx;
		int max = -1;
		for (int i = 1; i <= n; i++) {
			int cnt = 0;
			string s;
			getline(cin, s);
			for (int j = 0; j < 25; j++) {
				if (s[j] == 'X') {
					cnt++;
				}
			}
			nx.push_back(cnt);
			if (cnt > max) {
				max = cnt;
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans += max - nx[i];
		}
        cout << ans << "\n";
	}
	return 0;
}
