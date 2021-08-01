#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 1;
	while (cin >> t, t) {
		vector<queue<int>> teams(t);
		vector<int> tbl(1000000);
		vector<int> order;
		for (int i = 0; i < t; i++) {
			int n;
			cin >> n;
			for (int j = 0; j < n; j++) {
				int e;
				cin >> e;
				tbl[e] = i;
			}
		}
		string command;
		cout << "Scenario #" << tc++ << "\n";
		while (cin >> command, command != "STOP") {
			if (command == "ENQUEUE") {
				int x;
				cin >> x;
				teams[tbl[x]].push(x);
				if (find(order.begin(), order.end(), tbl[x]) == order.end()) {
					order.push_back(tbl[x]);
				}
			} else {
				for (int i = 0; i < order.size(); i++) {
					cout << teams[order[i]].front() << "\n";
					teams[order[i]].pop();
					if (teams[order[i]].empty()) {
						for (auto j = order.begin(); j != order.end(); j++) {
							if (*j == order[i]) {
								order.erase(j);
								break;
							}
						}
					}
					break;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
