#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		k ^= (k >> 1);
		cout << k << "\n";
	}
	return 0;
}
