#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		vector <int> s(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		s[n] = 1422;
		bool ok = true;
		sort(s.begin(), s.end());
		for (int i = 0; i < n; i++) {
			if (s[i + 1] - s[i] > 200) {
				ok = false;
				break;
			}
		}
		if (ok) {
			int b = 200 - (1422 - s[n - 1]);
			if (b < 1422 - s[n - 1]) {
				ok = false;
			}
		}

		if (ok) {
			cout << "POSSIBLE";
		} else {
			cout << "IMPOSSIBLE";
		}
		cout << "\n";
	}
	return 0;
}
