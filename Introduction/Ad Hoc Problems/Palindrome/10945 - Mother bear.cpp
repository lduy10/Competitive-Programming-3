#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	while (getline(cin, s), s != "DONE") {
		vector<char> w;
		for (int i = 0; i < s.size(); i++) {
			if (isalpha(s[i])) {
				w.push_back(tolower(s[i]));
			}
		}
		int l = 0, r = w.size() - 1;
		while (l < r && w[l] == w[r]) {
			l++;
			r--;
		}
		if (l >= r) {
			cout << "You won't be eaten!";
		} else {
			cout << "Uh oh..";
		}
		cout << "\n";
	}
	return 0;
}
