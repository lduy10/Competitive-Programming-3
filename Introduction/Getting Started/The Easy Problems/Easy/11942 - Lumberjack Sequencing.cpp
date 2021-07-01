#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	cout << "Lumberjacks:\n";
	while (n--) {
		int a1, a2;
		cin >> a1 >> a2;
		int i = 8;
		bool ordered = true;
		int a0 = a2;
		while (i--) {
			int ai;
			cin >> ai;
			if ((a1 > a2 && ai > a0) || (a1 < a2 && ai < a0)){
				ordered = false;
			}
			a0 = ai;
		}
		if (ordered) {
			cout << "Ordered";
		} else {
			cout << "Unordered";
		}
		cout << "\n";
	}
	return 0;
}
