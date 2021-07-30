#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		list<char> ans;
		int i = 0;
		while (i < s.size()) {
			if (s[i] == '[') {
				string tmp = "";
				i++;
				while (i < s.size()) {
					if (s[i] == '[') {
						for (int j = tmp.size() - 1; j >= 0; j--) {
							ans.push_front(tmp[j]);
						}
						tmp = "";
					} else if (s[i] == ']') {
						for (int j = tmp.size() - 1; j >= 0; j--) {
							ans.push_front(tmp[j]);
						}
						break;
					} else {
						tmp += s[i];
					}
					i++;
				}
				if (i == s.size()) {
					for (int j = tmp.size() - 1; j >= 0; j--) {
						ans.push_front(tmp[j]);
					}
				}
				continue;
			}
			if (s[i] != ']') {
				ans.push_back(s[i]);
			}
			i++;
		}
		for (auto x = ans.begin(); x != ans.end(); x++) {
			cout << *x;
		}
		cout << "\n";
	}
	return 0;
}
