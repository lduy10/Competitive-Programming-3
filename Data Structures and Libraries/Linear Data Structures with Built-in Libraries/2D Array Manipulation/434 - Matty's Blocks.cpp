#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> f(n), r(n);
		vector<bool> col(9, false), row(9, false);
		for (int i = 0; i < n; i++) {
			cin >> f[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> r[i];
		}
		int minBlocks = 0, maxBlocks = 0;
		for (int i = 0, p = n - 1; i < n; i++, p--) {
			for (int j = 0; j < n; j++) {
				if (r[p] == f[j] && !row[i] && !col[j]) {
					minBlocks += r[p];
					row[i] = true;
					col[j] = true;
				}
				maxBlocks += min(f[j], r[p]);	
			}
		}
		for (int i = 0, p = n - 1; i < n; i++, p--) {
			if (!row[i]) {
				minBlocks += r[p];
			}
			if (!col[i]) {
				minBlocks += f[i];
			}
		}
		cout << "Matty needs at least "<< minBlocks << " blocks, and can add at most " << maxBlocks - minBlocks << " extra blocks.\n";
	}
	return 0;
}
