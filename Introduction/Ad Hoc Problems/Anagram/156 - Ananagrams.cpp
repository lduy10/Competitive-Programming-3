#include <bits/stdc++.h>

using namespace std;

int main() {
	map <string, int> m;
	vector<string> ss;
	string s;
	while (cin >> s, s != "#") {
		ss.push_back(s);
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		sort(s.begin(), s.end());
		m[s]++;
	}
	sort(ss.begin(), ss.end());
	for (int i = 0; i < ss.size(); i++) {
		string tmp = ss[i];
		transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
		sort(tmp.begin(), tmp.end());
		if (m[tmp] == 1) {
			cout << ss[i] << "\n";
		}
	}
	return 0;
}
