#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	cin.ignore();
	while (t--) {
		map <string, vector<string>> m;
		vector <string> o;
		string s;
		while (getline(cin, s) && s != "") {
			string tmp = "";
			for (int i = 0; i < s.size(); i++) {
				if (s[i] != ' ')  {
					tmp += s[i];
				}
			}
			sort(tmp.begin(), tmp.end());
			if (m[tmp].size() == 0) {
				o.push_back(tmp);
			}
			m[tmp].push_back(s);
		}
		vector <string> ans;
		for (int i = 0; i < o.size(); i++) {
			sort(m[o[i]].begin(), m[o[i]].end());
			if (m[o[i]].size() > 1) {
				for (int j = 0; j < m[o[i]].size() - 1; j++) {
					for (int k = j + 1; k < m[o[i]].size(); k++) {
						string s = "";
						s += m[o[i]][j] + " = " + m[o[i]][k];
						ans.push_back(s);
					}
				}
			}
		}
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << "\n";
		}
		if (t) {
			cout << "\n";
		}
	}
	return 0;
}
