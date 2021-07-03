#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		int a, c;
		cin >> a;
		if (a == 0) break;
		cin >> c;
		int ans = 0;
		int d = a;
		for (int i = 0; i < c; i++) {
			int x;
			cin >> x;
			if (x < d) {
				ans += d - x;
			}
			d = x;
		}
		cout << ans << "\n";
	}
	return 0;
}
