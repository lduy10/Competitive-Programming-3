#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 1;
	cin >> t;
	while (t--) {
		vector<pair<string, int>> pile(53);
		for (int i = 1; i <= 52; i++) {
			cin >> pile[i].first;
			if (isdigit(pile[i].first[0])) {
				pile[i].second = pile[i].first[0] - '0';
			} else {
				pile[i].second = 10;
			}
		}
		int times = 3;
		int Y = 0;
		int i = 25;
		while (times--) {
			Y += pile[i].second;
			i -= 11 - pile[i].second;
		}
		cout << "Case " << tc++ << ": ";
		if (i >= Y) {
			cout << pile[Y].first;
		} else {
			cout << pile[25 + Y - i].first;
		}
		cout << "\n";
	}
	return 0;
}
