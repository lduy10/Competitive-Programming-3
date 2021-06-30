#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int ans = 0;
		vector<int> ins(n + 1);
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			if (s == "LEFT") {
				ans--;
				ins[i] = -1;
			} else if (s == "RIGHT") {
				ans++;
				ins[i] = 1;
			} else {
				int no;
				string as;
				cin >> as >> no;
				ans += ins[no];
				ins[i] = ins[no];
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
