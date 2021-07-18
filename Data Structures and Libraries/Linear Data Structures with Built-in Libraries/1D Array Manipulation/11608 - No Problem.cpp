#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, tc = 1;
	while (cin >> n, n >= 0) {
		vector <int> p (13);
		for (int i = 1; i <= 12; i++) {
			cin >> p[i];
		}
		int s = n;
		cout << "Case " << tc++ << ":\n";
		for (int i = 1; i <= 12; i++) {
			int x;
			cin >> x;
			if (s >= x) {
				s -= x;
				cout << "No problem! :D\n";
			} else {
				cout << "No problem. :(\n";
			}
			s += p[i];
		}
	}
	return 0;
}
