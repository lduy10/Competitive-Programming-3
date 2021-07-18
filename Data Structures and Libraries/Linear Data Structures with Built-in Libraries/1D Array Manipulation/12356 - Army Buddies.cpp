#include <bits/stdc++.h>

using namespace std;

struct Soldier {
	int index;
	int left;
	int right;
};

int main() {
	int s, b;
	while (cin >> s >> b, s, b) {
		vector<Soldier> soldiers(s + 2);
		soldiers[0].index = -1;
		soldiers[s + 1].index = -1;
		for (int i = 1; i <= s; i++) {
			soldiers[i].index = i;
		}
		for (int i = 1; i <= s; i++) {
			soldiers[i].left = soldiers[i - 1].index;
			soldiers[i].right = soldiers[i + 1].index;
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
				cout << soldiers[li].index;
			}
			cout << " ";
			if (ri == -1) {
				cout << "*";
			} else {
				cout << soldiers[ri].index;
			}
			cout << "\n";
		}
		cout << "-\n";
	}
	return 0;
}
