#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q, tc = 1;
	while (cin >> n >> q, n) {
		vector<int> marbles(n);
		for (int i = 0; i < n; i++) {
			cin >> marbles[i];
		}
		sort(marbles.begin(), marbles.end());
		cout << "CASE# " << tc++ << ":\n";
		while (q--) {
			int x;
			cin >> x;
			int index = lower_bound(marbles.begin(), marbles.end(), x) - marbles.begin();
			if (marbles[index] == x) {
				cout << x << " found at " << index + 1;
			} else {
				cout << x << " not found";
			}
			cout << "\n";
		}
	}
	return 0;
}
