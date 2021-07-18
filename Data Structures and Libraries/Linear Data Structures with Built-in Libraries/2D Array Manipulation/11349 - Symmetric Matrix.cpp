#include <bits/stdc++.h>

using namespace std;

bool symmetric(vector<vector<long long>> &matrix, int &cnt, int &n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] != matrix[n - i - 1][n - j - 1] 
			|| matrix[i][j] < 0 
			|| matrix[n - i - 1][n - j - 1] < 0) {
				return false;
			}
			cnt--;
			if (cnt == 0) {
				return true;
			}
		}
	}
}

int main() {
	int t, tc = 1;
	cin >> t;
	cin.ignore();
	while (t--) {
		int n;
		scanf("N = %d", &n);
		vector<vector<long long>> matrix(n, vector<long long> (n));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> matrix[i][j];
			}
		}

		int cnt = (n * n) % 2 == 0 ? (n * n) / 2 : (n * n + 1) / 2;
		cout << "Test #" << tc++ << ": ";
		if (symmetric(matrix, cnt, n)) {
			cout << "Symmetric.";
		} else {
			cout << "Non-symmetric.";
		}
		cout << "\n";
		cin.ignore();
	}
	return 0;
}
