#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	vector<long long> a;
	while (cin >> n) {
		a.push_back(n);
		sort(a.begin(), a.end());
		int sz = a.size();
		if (sz % 2 == 0) {
			cout << (a[sz / 2] + a[sz / 2 - 1]) / 2;
		} else {
			cout << a[sz / 2];
		}
		cout << "\n";
	}
	return 0;
}
