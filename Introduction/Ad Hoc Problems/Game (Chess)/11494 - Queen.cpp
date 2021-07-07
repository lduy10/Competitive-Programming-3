#include <bits/stdc++.h>

using namespace std;

int main() {
	int x1, y1, x2, y2;
	while (cin >> x1 >> y1 >> x2 >> y2) {
		if (x1 == y1 && y1 == x2 && x2 == y2 && y2 == 0) {
			break;
		}
		if (x1 == x2 && y1 == y2) {
			cout << 0;
		} else if (x1 == x2 || y1 == y2 || x1 - y1 == x2 - y2 || x1 + y1 == x2 + y2) {
			cout << 1;
		} else {
			cout << 2;
		}
		cout << "\n";
	}
	return 0;
}
