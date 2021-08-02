#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		vector<int> tbl(105, 0);
		cin >> n >> m;
		deque <int> q;
		vector <int> p;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (tbl[x] == 0) {
				p.push_back(x);
			}
			q.push_back(x);
			tbl[x]++;
		}
		int myJob = q[m];
		sort(p.begin(), p.end(), greater<int>());
		int ans = 0;
		bool done = false;
		for (int i = 0; i < p.size() && !done; i++) {
			while (tbl[p[i]] > 0) {
				if (q.front() == p[i]) {
					ans++;
					if (m == 0 && myJob == p[i]) {
						done = true;
						break;
					} else {
						m--;
						if (m == -1) {
							m = q.size() - 1;
						}
					}
					tbl[p[i]]--;
					q.pop_front();
					
				} else {
					if (m == 0) {
						m = q.size() - 1;
					} else {
						m--;
					}
					int front = q.front();
					q.pop_front();
					q.push_back(front);
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
