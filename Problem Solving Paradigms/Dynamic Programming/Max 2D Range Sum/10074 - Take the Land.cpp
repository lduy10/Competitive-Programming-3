#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> m >> n, m) {
        vector<vector<int>> matrix(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j]) matrix[i][j] = INT_MIN;
                else matrix[i][j] = 1;
                if (i > 0) matrix[i][j] += matrix[i - 1][j];
                if (j > 0) matrix[i][j] += matrix[i][j - 1];
                if (i > 0 && j > 0) matrix[i][j] -= matrix[i - 1][j - 1];
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = i; k < m; k++) {
                    for (int l = j; l < n; l++) {
                        int subMatrix = matrix[k][l];
                        if (i > 0) subMatrix -= matrix[i - 1][l];
                        if (j > 0) subMatrix -= matrix[k][j - 1];
                        if (i > 0 && j > 0) subMatrix += matrix[i - 1][j - 1];
                        ans = max(ans, subMatrix);
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}