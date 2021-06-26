#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	long long ans = 0;
	while (t--) {
		string op;
		cin >> op;
		if (op == "donate") {
			int x;
			cin >> x;
			ans += x;
		} else {
			cout << ans << "\n";
		}
	}
}