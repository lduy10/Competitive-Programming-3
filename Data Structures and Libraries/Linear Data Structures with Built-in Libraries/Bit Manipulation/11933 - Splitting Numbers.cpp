#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n;
	while (cin >> n, n) {
		long long a = 0, b = 0;
		int cnt = 0;
		for (int i = 0; i < 32; i++) {
			if (n & (1 << i)) {
				if (cnt % 2 == 0) {
					a |= (1 << i); 	
				} else {
					b |= (1 << i);
				}
				cnt++;
			}
		}
		cout << a << " " << b << "\n";
	}
	return 0;
}
