#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<long long> prices;
		long long ans = 0, cnt = 1;
		int l;
		while (cin >> l, l) {
			prices.push_back(l);
		}
		sort(prices.begin(), prices.end(), greater<int>());
		for (int i = 0; i < prices.size(); i++) {
			ans += 2 * pow(prices[i], cnt++);
		}
		if (ans <= 5000000) {
			cout << ans;
		}
		else {
			cout << "Too expensive";
		}
		cout << "\n";
	}
	return 0;
}
