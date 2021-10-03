#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    int t, tc = 0;
    string s;
    cin >> t;
    getline(cin, s);
    getline(cin, s);
    while (t--) {
        int n, m;
        vector<vector<int>> matrix;
        while (getline(cin, s), !s.empty()) {
            m = s.size();
            vector<int> row(m);
            for (int i = 0; i < m; i++) {
                (s[i] == '1') ? row[i] = 1 : row[i] = INT_MIN;
            }
            matrix.emplace_back(row);
        }
        n = matrix.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0) matrix[i][j] += matrix[i - 1][j];
                if (j > 0) matrix[i][j] += matrix[i][j - 1];
                if (i > 0 && j > 0) matrix[i][j] -= matrix[i - 1][j - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = i; k < n; k++) {
                    for (int l = j; l < m; l++) {
                        int subMatrix = matrix[k][l];
                        if (i > 0) subMatrix -= matrix[i - 1][l];
                        if (j > 0) subMatrix -= matrix[k][j - 1];
                        if (i > 0 && j > 0) subMatrix += matrix[i - 1][j - 1];
                        ans = max(ans, subMatrix);
                    }
                }
            }
        }
        if (tc++) cout << "\n";
        cout << ans << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}