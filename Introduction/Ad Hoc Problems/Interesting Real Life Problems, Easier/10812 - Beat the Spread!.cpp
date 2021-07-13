#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int s, d;
		cin >> s >> d;
		if (s < d) {
			cout << "impossible";
		} else {
			int y = (s - d) / 2;
			int x = s - y;
			if (abs(x - y) == d) {
				cout << x << " " << y;
			} else {
				cout << "impossible";
			}
		}
		cout << "\n";
		
	}
	return 0;
}
