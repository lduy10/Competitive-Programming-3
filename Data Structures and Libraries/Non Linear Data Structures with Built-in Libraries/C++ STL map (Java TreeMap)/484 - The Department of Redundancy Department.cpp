#include <bits/stdc++.h>

using namespace std;

int main() {
	map<int, int> m;
	int n;
	vector<int> order;
	while (cin >> n) {
		if (!m[n]) {
			order.push_back(n);
		}
		m[n]++;
	}
	for (int e : order) {
		cout << e << " " << m[e] << "\n";
	}
	return 0;
}
