#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    int n, m, tc = 0;
    while (cin >> n >> m) {
        vector<vector<int>> matrix(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) matrix[i][j] += matrix[i - 1][j];
                if (j > 0) matrix[i][j] += matrix[i][j - 1];
                if (i > 0 && j > 0) matrix[i][j] -= matrix[i - 1][j - 1];
            }
        }
        vector<vector<int>> newMatrix;
        for (int i = m - 1; i < n; i++) {
            vector<int> v;
            for (int j = m - 1; j < n; j++) {
                int subMatrix = matrix[i][j];
                if (i - m >= 0) subMatrix -= matrix[i - m][j];
                if (j - m >= 0) subMatrix -= matrix[i][j - m];
                if (i - m >= 0 && j - m >= 0) subMatrix += matrix[i - m][j - m];
                v.emplace_back(subMatrix);
            }
            newMatrix.emplace_back(v);
        }
        if (tc++) cout << "\n";
        int sum = 0;
        for (int i = newMatrix.size() - 1; i >= 0; i--) {
            for (int &j : newMatrix[i]) {
                sum += j;
                cout << j << "\n";
            }
        }
        cout << sum << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}