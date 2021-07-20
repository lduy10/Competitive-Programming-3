#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector<vector<int>> a(10, vector<int> (10, 0));
		for (int i = 1; i <= 9; i += 2) {
			for (int j = 1; j <= i; j += 2) {
				cin >> a[i][j];
			}
		}

		for (int i = 2; i <= 9; i += 2) {
			for (int j = 1; j <= i; j += 2) {
				a[i + 1][j + 1] = (a[i - 1][j] - a[i + 1][j] - a[i + 1][j + 2]) / 2;
				a[i][j] = a[i + 1][j] + a[i + 1][j + 1];
				a[i][j + 1] = a[i + 1][j + 1] + a[i + 1][j + 2];
			}
		}

		for(int i=1; i <= 9 ; i++) {
			for(int j = 1; j <= i; j++) {
				if (j != i) printf("%d ", a[i][j]);
				else printf("%d\n", a[i][j]);
			}
		}
	}
	return 0;
}
