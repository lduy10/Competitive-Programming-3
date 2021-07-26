#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, tc = 1;
	cin >> n;
	while (n--) {
		int c, r;
		cin >> c >> r;
		cout << "Case #" << tc++ << ":";
		if (r == c) {
			cout << " 0";
		} else {
			vector<int> q;
			for (int i = 1; i <= sqrt(c); i++) {
				if ((c - r) % i == 0) {
					q.push_back(i);
					if ((c - r) / i != i) {
						q.push_back((c - r) / i);
					}
				}
			}
			sort(q.begin(), q.end());
			for (int i = 0; i < q.size(); i++) {
				if (q[i] > r) {
					cout << " " << q[i];
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
