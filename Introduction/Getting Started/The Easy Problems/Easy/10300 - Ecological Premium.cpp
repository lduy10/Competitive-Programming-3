#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		long long sum = 0;
		int f;
		cin >> f;
		while (f--) {
			long long size, animals, ef;
			cin >> size >> animals >> ef;
			sum += size * ef;
		}
		cout << sum << "\n";
	}
	return 0;
}