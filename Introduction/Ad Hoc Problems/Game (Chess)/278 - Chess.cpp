#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int r, c, ans;
		char piece;
		cin >> piece >> r >> c;
		if (piece == 'k') {
			ans = r * c;
			ans = ans % 2 == 0 ? ans /= 2 : (ans + 1) / 2;
		} else if (piece == 'r') {
			ans = r;
		} else if (piece == 'Q') {
			ans = min(r, c);
		} else {
			if (c % 2 != 0) c++;
			if (r % 2 != 0) r++;
			ans = c / 2 * r / 2;
		}
		cout << ans << "\n";
	}
	return 0;
}
