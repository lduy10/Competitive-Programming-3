#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, r, c;
    while (cin >> n >> m >> r >> c) {
        if  (n == m && m == r && r == c && c == 0) break;
        vector<vector<int>> matrix(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < m;  j++) {
                matrix[i][j] = row[j] - '0';
            }
        }
        vector<vector<int>> a(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n - r + 1; i++) {
            for (int j = 0; j < m - c + 1; j++) {
                if (matrix[i][j] != a[i][j]) {
                    for (int k = i; k < i + r; k++) {
                        for (int l = j; l < j + c; l++) {
                            a[k][l] = 1 - a[k][l];
                        }
                    }
                    ans++;
                }
            }
        }
        for (int i = 0; i < n && ans != -1; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] != a[i][j]) {
                    ans = -1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}