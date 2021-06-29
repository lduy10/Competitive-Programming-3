#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int w;
		cin >> w;
		w--;
		int d, x, y;
		bool check = true;
		cin >> x >> y;
		d = x - y;	
		while (w--) {
			int y1, y2;
			cin >> y1 >> y2;
			if (d != y1 - y2 && check != false) {
				check = false;
			}
		}
		if (check) {
			cout << "yes\n";
		} else {
			cout << "no\n";
		}
		if (t) {
			cout << "\n";
		}	
	}
	return 0;
}