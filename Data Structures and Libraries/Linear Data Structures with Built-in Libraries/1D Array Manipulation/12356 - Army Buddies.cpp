#include <bits/stdc++.h>

using namespace std;

struct Soldier {
	int left;
	int right;
};

int main() {
	int s, b;
	while (cin >> s >> b, s, b) {
		vector<Soldier> soldiers(s + 1);
		for (int i = 1; i <= s; i++) {
			if (i == 1) {
				soldiers[i].left = -1;
			} else {
				soldiers[i].left = i - 1;
			}
			if (i == s) {
				soldiers[i].right = -1;
			} else {
				soldiers[i].right = i + 1;
			}
		}

		for (int i = 1; i <= b; i++) {
			int l, r;
			cin >> l >> r;
			int li = soldiers[l].left;
			int ri = soldiers[r].right;
			if (li != -1) {
				soldiers[li].right = ri;
			}
			if (ri != -1) {
				soldiers[ri].left = li;
			} 
			if (li == -1) {
				cout << "*";
			} else {
				cout << li;
			}
			cout << " ";
			if (ri == -1) {
				cout << "*";
			} else {
				cout << ri;
			}
			cout << "\n";
		}
		cout << "-\n";
	}
	return 0;
}
