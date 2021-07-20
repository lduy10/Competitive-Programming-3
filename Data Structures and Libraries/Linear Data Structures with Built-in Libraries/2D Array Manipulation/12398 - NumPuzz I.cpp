#include <bits/stdc++.h>

using namespace std;

struct Coordinate{
	int x;
	int y;
};

int main() {
	int tc = 1;
	vector<int> dx = {0, -1, 0, 1};
	vector<int> dy = {-1, 0, 1, 0};
	vector<Coordinate> map(127);
	map['a'] = {1, 1};
	map['b'] = {1, 2};
	map['c'] = {1, 3};
	map['d'] = {2, 1};
	map['e'] = {2, 2};
	map['f'] = {2, 3};
	map['g'] = {3, 1};
	map['h'] = {3, 2};
	map['i'] = {3, 3};
	string s;
	while (getline(cin ,s)) {
		vector<vector<int>> matrix(4, vector<int> (4, 0));
		int n = s.size() - 1;
		for (int i = n; i >= 0; i--) {
			auto c = map[s[i]];
			matrix[c.x][c.y]++;
			if (matrix[c.x][c.y] == 10) {
				matrix[c.x][c.y] = 0;
			}
			for (int j = 0; j < 4; j++) {
				int x1 = c.x + dx[j];
				int y1 = c.y + dy[j];
				if (x1 >= 1 && x1 <= 3 && y1 >= 1 && y1 <= 3) {
					matrix[x1][y1]++;
					if (matrix[x1][y1] == 10) {
						matrix[x1][y1] = 0;
					}
				}
			}
		}
		cout << "Case #" << tc++ << ":\n";
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				if (j > 1) {
					cout << " ";
				}
				cout << matrix[i][j];
			}
			cout << "\n";
		}			
	}
	return 0;
}
