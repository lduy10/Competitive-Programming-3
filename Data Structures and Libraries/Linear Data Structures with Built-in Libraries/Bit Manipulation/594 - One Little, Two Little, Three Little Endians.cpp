#include <bits/stdc++.h>

using namespace std;

int main() {
	int S;
	while (cin >> S) {
		cout << S << " converts to ";
		int ans = 0;
		for (int i = 0; i < 4; i++) {
			ans <<= 8;
			ans |= (S & 255);
			S >>= 8;
		}
		cout << ans << "\n";
	}
	return 0;
}
