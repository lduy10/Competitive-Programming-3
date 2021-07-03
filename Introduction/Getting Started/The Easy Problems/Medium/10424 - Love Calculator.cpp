#include <bits/stdc++.h>

using namespace std;

int calSum(int n) {
	while (n >=  10) {
		n = n / 10 + n % 10;
	}
	return n;
}

int main() {
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	map <char, int> myMap;
	for (int i = 1; i <= 26; i++) {
		myMap[alphabet[i - 1]] = i;
		myMap[tolower(alphabet[i - 1])] = i;
	}
	int t = 1, m;
	string s;
	while (getline(cin, s)) {
		int n = 0;
		for (int i = 0; i < s.size(); i++) {
			if (isalpha(s[i])) {
				n += myMap[s[i]];
			}
		}
		int o = calSum(n);
		if (t % 2 != 0) {
			m = o;
		} else if (o < m){
			printf("%.2lf %%\n", (double) o / m * 100);
		} else {
			printf("%.2lf %%\n", (double) m / o * 100);
		}
		t++;
	}
	return 0;
}
