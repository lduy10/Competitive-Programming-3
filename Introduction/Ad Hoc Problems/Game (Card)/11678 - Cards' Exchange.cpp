#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, x;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}
		set<int> A, B, C;
		for (int i = 1; i <= a; i++) {
			cin >> x;
			A.insert(x);
			C.insert(x);
		}
		for (int i = 1; i <= b; i++) {
			cin >> x;
			B.insert(x);
			C.insert(x);
		}
		cout << min(C.size() - A.size(), C.size() - B.size()) << "\n";
	}
	return 0;
}
