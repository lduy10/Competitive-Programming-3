#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> matrix(n + 1, vector<int> (n + 1));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				char c;
				cin >> c;
				matrix[i][j] = c - '0';
			}
		}
		int m;
		cin >> m;
		while (m--) {
			string o;
			int a, b;
			cin >> o;
			if (o == "row") {
				cin >> a >> b;
				for (int i = 1; i <= n; i++) {
					swap(matrix[a][i], matrix[b][i]);
				}
			} else if (o == "col") {
				cin >> a >> b;
				for (int i = 1; i <= n; i++) {
					swap(matrix[i][a], matrix[i][b]);
				}
			} else if (o == "inc") {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) {
						matrix[i][j]++;
						if (matrix[i][j] == 10) {
							matrix[i][j] = 0;
						}
					}
				}
			} else if (o == "dec") {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) {
						matrix[i][j] = (matrix[i][j] - 1) % 10;
						if (matrix[i][j] == -1) {
							matrix[i][j] = 9;
						}
					}
				}
			} else {
				for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= n; j++) {
						if (i >= j) {
							swap(matrix[i][j], matrix[j][i]);
						}	
					}
				}
			}
		}
		cout << "Case #" << tc++ << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << matrix[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
