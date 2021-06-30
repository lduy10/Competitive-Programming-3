#include<bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		int b, n;
		cin >> b >> n;
		if (b == 0 && n == 0) {
			break;
		}
		vector<int> moneyReserves(b + 1);
		for (int i = 1; i <= b; i++) {
			cin >> moneyReserves[i];
		}
		for (int i = 1; i <= n; i++) {
			int d, c, v;
			cin >> d >> c >> v;
			moneyReserves[d] -= v;
			moneyReserves[c] += v;
		}
		int i = 1;
		while (moneyReserves[i] >= 0 && i <= b) {
			i++;
		}
		if (i <= b) {
			cout << "N";
		} else {
			cout << "S";
		}
		cout << "\n";
	}
	return 0;
}
