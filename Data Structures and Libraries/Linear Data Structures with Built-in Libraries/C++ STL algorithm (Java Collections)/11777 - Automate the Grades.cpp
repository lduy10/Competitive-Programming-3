#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 1;
	cin >> t;
	while (t--) {
		double t1, t2, f, a, ct1, ct2, ct3;
		cin >> t1 >> t2 >> f >> a >> ct1 >> ct2 >> ct3;
		double sum = t1 + t2 + f + a + max({ct1 + ct2, ct1 + ct3, ct2 + ct3}) / 2;
		cout << "Case " << tc++ << ": ";
		if (sum >= 90) {
			cout << "A";
		} else if (sum >= 80) {
			cout << "B";
		} else if (sum >= 70) {
			cout << "C";
		} else if (sum >= 60) {
			cout << "D";
		} else {
			cout << "F";
		}
		cout << "\n";
	}
	return 0;
}
