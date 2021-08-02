#include <bits/stdc++.h>

using namespace std;

int main() {
	int c;
	cin >> c;
	while (c--) {
		int l, m;
		cin >> l >> m;
		l *= 100;
		int tmpLength = l;
		string b = "left";
		queue<int> lb, rb;
		for (int i = 0; i < m; i++) {
			int length;
			string bank;
			cin >> length >> bank;
			if (bank == "left") {
				lb.push(length);
			} else {
				rb.push(length);
			}
		}
		int ans = 0;
		while (!lb.empty() || !rb.empty()) {
			l = tmpLength;
			if (b == "left") {
				while (!lb.empty() && l >= lb.front()) {
					l -= lb.front();
					lb.pop();
				}
			} else {
				while (!rb.empty() && l >= rb.front()) {
					l -= rb.front();
					rb.pop();
				}
			}
			if (b == "left") {
				b = "right";
			} else {
				b = "left";
			}
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}

