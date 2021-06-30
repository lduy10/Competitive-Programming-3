#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int max;
		cin >> max;
		n--;
		while (n--) {
			int c;
			cin >> c;
			if (c > max) {
				max = c;
			}
		}
		printf("Case %d: %d\n", tc, max);
		tc++;
	}
	return 0;
}
