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
		if (a1 > a2) {
			while (i--) {
				int ai;
				cin >> ai;
				if (ai > a2 && ordered) {
					ordered = false;
				}
				a2 = ai;
			}
		} else {
			while (i--) {
				int ai;
				cin >> ai;
				if (ai < a2 && ordered) {
					ordered = false;
				}
				a2 = ai;
			}
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
