#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, tc = 1;
	while (cin >> n, n) {
		vector<int> s(n);
		int b = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			b += s[i];
		}
		int h = b / n;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] < h) {
				ans += h - s[i];
			}
		}
		cout << "Set #" << tc++ << "\n";
		cout << "The minimum number of moves is " << ans << ".\n\n";
	}
	return 0;
}
