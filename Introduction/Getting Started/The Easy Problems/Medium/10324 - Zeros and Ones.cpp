#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	int tc = 1;
	while (cin >> s) {
		int n;
		cin >> n;
		cout << "Case " << tc++ << ":\n";
		while (n--) {
			int a, b;
			cin >> a >> b;
			bool check = true;
			if (a > b) {
				swap(a, b);
			}
			for (int i = a; i < b; i++) {
				if (s[i] != s[i + 1]) {
					check = false;
				}
			}
			if (check) cout << "Yes";
			else cout << "No";
			cout << "\n";
		}
	}
	return 0;
}
