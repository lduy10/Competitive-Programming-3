#include <bits/stdc++.h>

using namespace std;

int recursiveF(int n) {
	if (n < 10) {
		return n;
	} else {
		return n % 10 + recursiveF(n / 10);
	}
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		while (n >= 10) {
			n = recursiveF(n);
		}
		cout << n << "\n"; 
	}
	
	return 0;
}