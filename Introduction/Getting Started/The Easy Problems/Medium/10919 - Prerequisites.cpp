#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		int k, m;
		cin >> k;
		if (k == 0) break;
		cin >> m;
		map<int, int> courses;
		for (int i = 0; i < k; i++) {
			int n;
			cin >> n;
			courses[n] = 1;
		}
		bool ok = true;
		for (int i = 0; i < m; i++) {
			int c, r;
			cin >> c >> r;
			int cnt = 0;
			for (int i = 0; i < c; i++) {
				int ci;
				cin >> ci;
				if (courses[ci] == 1) cnt++;
			}
			if (cnt < r) ok = false;
		}
		if (ok) {
			cout << "yes";
		} else {
			cout << "no";
		}
		cout << "\n"; 
	}
	return 0;
}
