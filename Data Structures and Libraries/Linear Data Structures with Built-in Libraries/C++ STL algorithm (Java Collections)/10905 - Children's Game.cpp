#include <bits/stdc++.h>

using namespace std;

bool comparator(string &a, string &b) {
	return a + b > b + a;
}

int main() {
	int n;
	while (cin >> n, n) {
		vector<string> numbers(n);
		for (int i = 0; i < n; i++) {
			cin >> numbers[i];
		}
		sort(numbers.begin(), numbers.end(), comparator);
		for (int i = 0; i < n; i++)  {
			cout << numbers[i];
		}
		cout << "\n";
	}
	return 0;
}
