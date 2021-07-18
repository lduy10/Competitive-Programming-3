#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 1;
	cin >> t;
	while (t--) {
		vector <int> tbl(10005, 10), a, b, c;
		for (int i = 1; i <= 3; i++) {
			int s;
			cin >> s;
			for (int j = 1; j <= s; j++) {
				int p;
				cin >> p;
				if (i == 1) {
					tbl[p] -= 1;
				} else if (i == 2) {
					tbl[p] -= 3;
				} else if (i == 3) {
					tbl[p] -= 5;
				}
			}
		}
		for (int i = 0; i <= 10000; i++) {
			if (tbl[i] == 9) {
				a.push_back(i);
			} else if (tbl[i] == 7) {
				b.push_back(i);			
			} else if (tbl[i] == 5) {
				c.push_back(i);
			}
		}
		cout << "Case #" << tc++ << ":\n";
		int na = a.size(), nb = b.size(), nc = c.size();
		if (na >= nb && na >= nc) {
			cout << 1 << " " << na;
			for (int i = 0; i < na; i++) {
				cout << " " << a[i];
			}
			cout << "\n";
		}
		if (nb >= na && nb >= nc) {
			cout << 2 << " " << nb;
			for (int i = 0; i < nb; i++) {
				cout << " " << b[i];
			}
			cout << "\n";
		}
		if (nc >= na && nc >= nb) {
			cout << 3 << " " << nc;
			for (int i = 0; i < nc; i++) {
				cout << " " << c[i];
			}
			cout << "\n";
		}
	}

	return 0;
}
