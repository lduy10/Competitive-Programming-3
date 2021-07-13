#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<int> p(1000005, 1);
		vector<int> sl(101, 0);
		int a, b, c;
		cin >> a >> b >> c;
		int turn = 1;
		for (int i = 1; i <= b; i++) {
			int u, v;
			cin >> u >> v;
			sl[u] = v;
		}
		bool end = false;
		for (int i = 1; i <= c; i++) {
			int r;
			cin >> r;
			if (p[turn] + r <= 100 && !end) {
				if (sl[p[turn] + r] == 0) {
					p[turn] += r; 
				} else {
					p[turn] = sl[p[turn] + r];
				}
				if (p[turn] == 100) {
					end = true;
				}
			}
			turn++;
			if (turn > a) {
				turn = 1;
			} 
		}
		for (int i = 1; i <= a; i++) {
			printf("Position of player %d is %d.\n", i, p[i]);
		}
	}
	return 0;
}
