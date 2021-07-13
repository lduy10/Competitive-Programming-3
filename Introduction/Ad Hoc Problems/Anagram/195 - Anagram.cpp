#include <bits/stdc++.h>

using namespace std;

bool comparator(char &a, char &b) {
	if (tolower(a) == tolower(b)) {
		return a < b;
	}
	return tolower(a) < tolower(b);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		sort(s.begin(), s.end(), comparator);
		do {
			cout << s << "\n";
		} while (next_permutation(s.begin(), s.end(), comparator));
	}
	return 0;
}
