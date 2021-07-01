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
	int j = 0;
	while (people[n - 1].second == false || j != m) {
		if (i == n) {
			i = 0;
		}
		if (j == m) {
			j = 0;
		}
		people[i].second = true;
		cout << people[i].first << ": " << words[j] << "\n";
		i++;
		j++;
	}
	return 0;
}
