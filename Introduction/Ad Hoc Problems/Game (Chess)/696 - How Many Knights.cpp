#include <bits/stdc++.h>

using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) {
			break;
		}
		int minN = min(m, n), maxN = max(m, n), ans;
		if (minN == 1) {
			ans = maxN;
		}
		else if (minN == 2) {
			ans = 4 * (maxN / 4) + 2 * min(2, maxN % 4);
		} else {
			ans = (m * n + 1) / 2;
		}
		printf("%d knights may be placed on a %d row %d column board.\n", ans, m, n);
	}
	return 0;
}
