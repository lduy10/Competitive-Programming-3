#include <bits/stdc++.h>

using namespace std;

int main() {
	int r;
	string s, g;
	while (cin >> r, r != -1) {
		cin >> s >> g;
		int cnt = 0, strokes = 7;
		map<char, int> w, used;
		for (int i = 0; i < s.size(); i++) {
			if (!w[s[i]]) {
				w[s[i]]++;
				cnt++;
			}
		}

		for (int i = 0; i < g.size(); i++) {
			if (!used[g[i]]) {
				used[g[i]]++;
				if (w[g[i]]) {
					cnt--;
					w[g[i]]--;
				} else {
					strokes--;
				}
				if (!cnt || !strokes) {
					break;
				}
			}
		}
		cout << "Round " << r << "\n";
		if (!strokes) {
			cout << "You lose.";
		} else if (cnt) {
			cout << "You chickened out.";
		} else {
			cout << "You win.";
		}
		cout << "\n";
	}
	return 0;
}
