#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		bitset<1000001> bset;
		bool conflict = false;
		int s, e, t;
		while (n--) {
			cin >> s >> e;
			for (int i = s; i < e; i++) {
				if (bset[i] == 1) {
					conflict = true;
					break;
				}
				bset[i] = 1;
			}
		}
		while (m--) {
			cin >> s >> e >> t;
			while (s < 1000000) {
				for (int i = s; i < e; i++) {
					if (i > 1000000) {
						continue;
					} 
					if (bset[i] == 1) {
						conflict = true;
						break;
					}
					bset[i] = 1;
				}
				s += t;
				e += t;
			}
		}
		if (conflict) {
			cout << "CONFLICT";
		} else {
			cout << "NO CONFLICT";
		}
		cout << "\n";
	}
	return 0;
}
