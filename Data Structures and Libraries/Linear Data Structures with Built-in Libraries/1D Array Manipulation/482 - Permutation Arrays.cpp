#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		cin.ignore();
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		stringstream ss;
		vector<int> indices(1000000);
		ss << s1;
		int n = 1;
		while (ss >> indices[n]) {
			n++;
		}
		ss.clear();
		ss << s2;
		vector<string> ans(1000000);
		int index = 1;
		while (ss >> ans[indices[index]]) {
			index++;
		}
		for (int i = 1; i < n; i++) {
			cout << ans[i] << "\n";
		}
		if (t) {
			puts("");
		}
 	}
	return 0;
}
