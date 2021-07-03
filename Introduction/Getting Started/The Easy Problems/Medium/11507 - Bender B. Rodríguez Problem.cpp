#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		int l;
		cin >> l;
		if (l == 0) break;
		string ans = "+x";
		for (int i = 0; i < l - 1; i++) {
			string d;
			cin >> d;
			if (d != "No") {
				if (ans[1] == d[1]) {
					if (ans[0] == d[0]) {
						ans = "-x";
					} else {
						ans = "+x";
					}
				} else if (ans[1] == 'x') {
					if (ans[0] == '-') {
						if (d[0] == '-') {
							ans[0] = '+';
						} else {
							ans[0] = '-';
						}
					} else {
						ans[0] = d[0];
					}
					ans[1] = d[1];
				} else if (ans[1] == 'y' || ans[1] == 'z') {
					continue;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
