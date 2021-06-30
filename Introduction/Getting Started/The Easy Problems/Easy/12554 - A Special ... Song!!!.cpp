#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<string> words = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
	int n;
	cin >> n;
	vector<pair<string, bool>> people(n);
	for (int i = 0; i < n; i++) {
		cin >> people[i].first;
	}
	int m = words.size();
	int i = 0;
	int p = 0;
	while (people[n - 1].second == false || p != m) {
		if (i == n) {
			i = 0;
		}
		if (p == m) {
			p = 0;
		}
		people[i].second = true;
		cout << people[i].first << ": " << words[p] << "\n";
		i++;
		p++;
	}
	return 0;
}
