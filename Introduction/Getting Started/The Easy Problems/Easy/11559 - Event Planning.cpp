#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, b, h, w;
	while (scanf("%d %d %d %d", &n, &b, &h, &w) != EOF) {
		int ans = 100000000;
		for (int i = 0; i < h; i++) {
			int price;
			cin >> price;
			for (int i = 0; i < w; i++) {
				int beds;
				cin >> beds;
				if (beds >= n && ans > n * price && b >= n * price) {
					ans = n * price;
				}
			}
		}
		if (ans != 100000000) {
			cout << ans;
		} else {
			cout << "stay home";
		}
		cout << "\n";
	}
	return 0;
}