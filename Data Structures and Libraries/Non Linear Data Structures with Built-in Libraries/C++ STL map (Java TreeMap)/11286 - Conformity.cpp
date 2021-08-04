#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		map<string, int> m;
		int max = INT_MIN;
		while (n--) {
			vector<string> courses(5);
			for (int i = 0; i < 5; i++) {
				cin >> courses[i];
			}
			sort(courses.begin(), courses.end());
			string s = "";
			for(auto e : courses) {
				s += e;
			}
			m[s]++;
			if (max < m[s]) {
				max = m[s];
			}
		}
		int ans = 0;
		for (auto i = m.begin(); i != m.end(); i++) {
			if (i -> second == max) {
				ans += max;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
