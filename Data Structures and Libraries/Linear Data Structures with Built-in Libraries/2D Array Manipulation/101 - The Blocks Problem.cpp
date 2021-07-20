#include <bits/stdc++.h>

using namespace std;

struct Coordinate {
	int x;
	int y;
};

int main() {
	int n;
	cin >> n;
	vector<Coordinate> m(25);
	vector<vector<int>> p(n);
	for (int i = 0; i < n; i++) {
		m[i] = {i, 0};
		p[i].push_back(i);
	}
	string cmd, type;
	int a, b;
	while(cin >> cmd, cmd != "quit") {
		cin >> a >> type >> b;
		auto pA = m[a];
		auto pB = m[b];
		int xA = pA.x, yA = pA.y;
		int xB = pB.x, yB = pB.y;
		if (a == b || xA == xB) {
			continue;
		}
		if (cmd == "move") {
			if (type == "onto") {
				for (int i = yB + 1; i < p[xB].size(); i++) {
					p[p[xB][i]].push_back(p[xB][i]);
					m[p[xB][i]] = {p[xB][i], 0};
				}
				p[xB].resize(yB + 1);
			}
			for (int i = yA + 1; i < p[xA].size(); i++) {
				p[p[xA][i]].push_back(p[xA][i]);
				m[p[xA][i]] = {p[xA][i], 0};
			}
			p[xA].resize(yA);
			p[xB].push_back(a);
			m[a] = {xB, p[xB].size() - 1};
		} else {
			if (type == "onto") {
				for (int i = yB + 1; i < p[xB].size(); i++) {
					p[p[xB][i]].push_back(p[xB][i]);
					m[p[xB][i]] = {p[xB][i], 0};
				}
				p[xB].resize(yB + 1);
			}
			for (int i = yA; i < p[xA].size(); i++) {
				p[xB].push_back(p[xA][i]);
				m[p[xA][i]] = {xB, p[xB].size() - 1};
			}
			p[xA].resize(yA);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << i << ":";
		for (int j = 0; j < p[i].size(); j++) {
			cout << " " << p[i][j] ;
		}
		cout << "\n";
	}
	return 0;
}
