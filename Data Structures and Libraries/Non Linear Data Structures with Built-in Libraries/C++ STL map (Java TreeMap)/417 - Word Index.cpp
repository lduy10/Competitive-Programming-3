#include <bits/stdc++.h>

using namespace std;

string alphabet = "?abcdefghijklmnopqrstuvwxyz";
vector<char> l(27);
vector<int> c;
map<string, int> myMap;
int n = 26, id = 1, sz = 1;

void initCombination() {
	c.clear();
	for (int i = 1; i <= sz; i++) {
		c.push_back(i);
	}
}

bool nextCombination() {
	int k = c.size();
	for (int i = k - 1; i >= 0; i--) {
		if (c[i] < n - k + i + 1) {
			c[i]++;
			for (int j = i + 1; j < k; j++) {
				c[j] = c[j - 1] + 1;
			}
			return true;
		}
	}
	return false;
}

void init() {
	for (int i = 1; i <= 26; i++) {
		l[i] = alphabet[i];
	}
	while (c.size() < 5) {
		initCombination();
		sz++;
		do {
			string s = "";
			for (int i = 0; i < c.size(); i++) {
				s += l[c[i]];
			}
			myMap[s] = id++;
		} while (nextCombination());
	}
}

int main() {
	init();
	string s;
	while (cin >> s) {
		cout << myMap[s] << "\n";
	}
	return 0;
}

