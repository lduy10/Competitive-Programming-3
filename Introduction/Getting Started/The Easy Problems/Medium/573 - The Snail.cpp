#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		double h, u, d, f;
		cin >> h >> u >> d >> f;
		if (h == 0) break;
		int day = 1;
		f = f / 100 * u;
		double height = 0;
		while (true) {
			height += u;
			if (height > h) break;
			u -= f;
			if (u < 0) u = 0;
			height -= d;
			if (height < 0) break;
			day++;
		}
		if (height > 0) cout << "success on day " << day;
		else cout << "failure on day " << day;
		cout << "\n";
	}
	return 0;
}
