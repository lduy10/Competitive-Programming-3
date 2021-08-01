#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		vector<int> order(n);
		while (cin >> order[0], order[0]) {
			for (int i = 1; i < n; i++) {
				cin >> order[i];
			}
			bool ok = true;
			stack<int> s;
			int x = 0;
			for (int i = 1; i <= n; i++) {
				while (!s.empty() && s.top() == order[x]) {
					x++;
					s.pop();
				}
				if (order[x] == i) {
					x++;
				} else {
					s.push(i);
				}
			}
			while (!s.empty()) {
				if (s.top() != order[x]) {
					ok = false;
					break;
				}
				x++;
				s.pop();
			}
			if (ok) {
				cout << "Yes";
			} else {
				cout << "No";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
