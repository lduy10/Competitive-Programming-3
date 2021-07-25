#include <bits/stdc++.h>

using namespace std;

bool comparator(int &a, int &b) {
	return abs(a) > abs(b);
}

int main() {
	int p;
	cin >> p;
	while (p--) {
		int n;
		cin >> n;
		if (n == 0) {
			cout << 0;
		} else {
			vector<int> f(n);
			for (int i = 0; i < n; i++) {
				cin >> f[i];
			}
			sort(f.begin(), f.end(), comparator);
			int ans = 1, tmp = f[0];
			for (int i = 0; i < n; i++) {
				if (tmp < 0 && f[i] > 0 || tmp > 0 && f[i] < 0) {
					ans++;
					tmp = f[i];
				}
			}
			cout << ans;
		}
		cout << "\n";
	}
	return 0;
}
