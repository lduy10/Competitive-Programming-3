#include <bits/stdc++.h>

using namespace std;

int main() {
	int g;
	while (cin >> g, g) {
		string s;
		cin >> s;
		int n = s.size() / g;
		int cnt = 0;
		string t = "";
		for (int i = 0; i < s.size(); i++) {
			t += s[i];
			cnt++;
			if (cnt == n) {
				reverse(t.begin(), t.end());
				cout << t;
				cnt = 0;
				t = "";
			}
		}
		cout << "\n";
	}
	return 0;
}
