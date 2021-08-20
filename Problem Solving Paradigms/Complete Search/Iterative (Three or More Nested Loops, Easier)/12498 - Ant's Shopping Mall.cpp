#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, tc = 1;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> matrix(r, vector<char>(c));
        vector<vector<int>> zeroes(r);
        for (int i = 0; i < r; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < c; j++) {
                matrix[i][j] = row[j];
                if (row[j] == '0') {
                    zeroes[i].emplace_back(j);
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < c && ans != -1; i++) {
            int minCol = 0;
            for (int j = 0; j < r; j++) {
                if (zeroes[j].empty()) {
                    ans = -1;
                    break;
                }
                int minRow = INT_MAX;
                if (matrix[j][i] == '0') {
                    minRow  = 0;
                    continue;
                }
                for (int k : zeroes[j]) {
                    if (minRow > abs(i - k)) {
                        minRow = abs(i - k);
                    }
                }
                minCol += minRow;
            }
            if (minCol < ans) {
                ans = minCol;
            }
        }
        cout << "Case " << tc++ << ": " << ans << "\n";
    }
    return 0;
}