#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		vector <int> car(n + 1, -69);
		bool possible = true;
		for (int i = 1; i <= n; i++) {
			int c, p;
			cin >> c >> p;
			if (!possible) {
				continue;
			}
			if (i + p > n || i + p < 1 || car[i + p] != -69) {
				possible = false;
			} else {
				car[i + p] = c;
			}
		}
		if (possible) {
			for (int i = 1; i <= n; i++) {
				if (i > 1) {
					cout << " ";
				}
				cout << car[i];
			}
		} else {
			cout << -1;
		}
        cout << "\n";
	}
	return 0;
}
