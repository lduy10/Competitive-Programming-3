#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n, n != 0) {
		vector <int> ml(n + 1);
		for (int i = 0; i < n; i++) {
			cin >> ml[i];
		}
		ml[n] = ml[0];
		int s, cnt = 0;
		if (ml[n - 1] < ml[0]) {
			s = 1;
		} else if (ml[n - 1] > ml[0]){
			s = 0;
		}
		for (int i = 0; i < n; i++) {
			if (ml[i] < ml[i + 1] && s == 0) {
				cnt++;
				s = 1;
			} else if (ml[i] > ml[i + 1] && s == 1) {
				cnt++;
				s = 0;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
