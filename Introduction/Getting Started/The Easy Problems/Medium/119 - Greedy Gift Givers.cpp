#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, t = 0;
	while (scanf("%d", &n) != EOF) {
		map<string, int> people;
		vector<string> names;
		for (int i = 0; i < n; i++) {
			string name;
			cin >> name;
			names.push_back(name);
		}
		for (int i = 0; i < n; i++) {
			string name;
			int money, friends;
			cin >> name >> money >> friends;
			if (friends != 0) {
				people[name] -= money / friends * friends;
				for (int j = 0; j < friends; j++) {
					string fname;
					cin >> fname;
					people[fname] += money / friends;
				}
			}
		}
		if (t > 0) cout << "\n";
		for (int i = 0; i < n; i++) {
			cout << names[i] << " " << people[names[i]] << "\n";
		}
		t++;
	}
	return 0;
}
