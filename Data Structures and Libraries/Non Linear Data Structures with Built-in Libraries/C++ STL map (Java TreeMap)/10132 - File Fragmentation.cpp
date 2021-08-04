#include <bits/stdc++.h>

using namespace std;

int main() {
//	ofstream of("OUTPUT.DAT");
	int t;
	cin >> t;
	cin.ignore();
	cin.ignore();
	while (t--) {
		vector<string> fragments;
		string s;
		int minL = INT_MAX, maxL = INT_MIN;
		while (getline(cin, s), s.size()) {
			int sz = s.size();
			if (minL > sz) {
				minL = sz;
			}
			if (maxL < sz) {
				maxL = sz;
			}
			fragments.push_back(s);
		}
		int originL = minL + maxL;
		vector<string> c;
		for (int i = 0; i < fragments.size() - 1; i++) {
			for (int j = i + 1; j < fragments.size(); j++) {
				string a = fragments[i] + fragments[j];
				string b = fragments[j] + fragments[i];
				if (a.size() != originL) {
					continue;
				}
				c.push_back(a);
				c.push_back(b);
			}
		}
		map<string, int> m;
		string ans = "";
		for (int i = 0; i < c.size(); i++) {
			m[c[i]]++;
			if (m[ans] < m[c[i]]) {
				ans = c[i];
			}
		}
		cout << ans << "\n";
		if (t) {
			cout << "\n";
		}
	}
//	of.close();
	return 0;
}
