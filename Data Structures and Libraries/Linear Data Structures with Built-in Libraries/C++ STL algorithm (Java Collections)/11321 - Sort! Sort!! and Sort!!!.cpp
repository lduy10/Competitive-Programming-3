#include <bits/stdc++.h>

using namespace std;

int n, m;

bool comparator(int &a, int &b) {
	if (a % m != b % m) {
		return a % m < b % m;
	} else if (a % 2 == 0 && b % 2 == 0) {
		return a < b;
	} else if (a % 2 != 0 && b % 2 != 0) {
		return a > b;
	} else {
		return a % 2 != 0 && b % 2 == 0;
	}
}

int main() {
	while (cin >> n >> m) {
		cout << n << " " << m << "\n";
		if (n == 0 && m == 0) {
			break;
		}
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end(), comparator);
		for (int i = 0; i < n; i++) {
			cout << v[i] << "\n";
		}
	}
	return 0;
}
