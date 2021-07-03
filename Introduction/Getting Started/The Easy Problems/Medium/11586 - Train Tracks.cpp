#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	cin.ignore();
	while (t--) {
		string list;
		getline(cin, list);
		int m = 0, fm = 0;
		for (int i = 0; i < list.size(); i++) {
			if (list[i] == 'M') m++;
			else if (list[i] == 'F') fm++;
		}
		if (m == fm && list.size() != 2) cout << "LOOP";
		else cout << "NO LOOP";
		cout << "\n";
	}
	return 0;
}
