#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		int l;
		cin >> l;
		if (l == 0) break;
		int ans = 2000001, lastR = -2000001, lastD = -2000001;
		for (int i = 1; i <= l; i++) {
			char c;
			cin >> c;
			if (c == 'Z') ans = 0;
			if (ans != 0) {
				if (c == 'R') {
					ans = min(ans, i - lastD);
					lastR = i;
				} else if (c == 'D') {
					ans = min(ans, i - lastR);
					lastD = i;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
