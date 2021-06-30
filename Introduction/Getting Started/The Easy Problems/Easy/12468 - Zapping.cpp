#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1) break;
		int res;
		if (a > b) {
			res = a - b < b + 100 - a ? a - b : b + 100 - a;
		} else {
			res = b - a < a + 100 - b ? b - a : a + 100 - b;
		}
		cout << res << "\n";
	}
	return 0;
}
