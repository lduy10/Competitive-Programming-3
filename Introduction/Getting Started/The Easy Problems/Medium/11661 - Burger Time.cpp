#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		int l;
		cin >> l;
		if (l == 0) break;
		int min = 2000001, cnt = 0;
		char t = '?';
		for (int i = 1; i <= l; i++) {
			cnt++;
			char c;
			cin >> c;
			if (c == 'Z') min = 0;
			else if (t == '?' && c != '.') {
				t = c;
				cnt = 0;
			} else if (t == 'R' && c == 'R' || t == 'D' && c == 'D') {
				cnt = 0;
			} else if (t == 'R' && c == 'D' || t == 'D' && c == 'R') {
				t = c;
				if (cnt < min) {
					min = cnt;
				}
				cnt = 0;
			}
		}
		cout << min << "\n";
	}
	return 0;
}
