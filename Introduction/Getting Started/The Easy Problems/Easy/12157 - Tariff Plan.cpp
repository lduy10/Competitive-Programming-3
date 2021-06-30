#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int Mile = 0, Juice = 0;
		for (int i = 0; i < n; i++) {
			int cd;
			cin >> cd;
			Mile += (cd / 30 + 1) * 10;
			Juice += (cd / 60 + 1) * 15;
		}
		printf("Case %d:", tc++);
		if (Mile <= Juice) printf(" Mile");
		if (Juice <= Mile) printf(" Juice");
		printf(" %d\n", min(Mile, Juice));
	}
	return 0;
}
