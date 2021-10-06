#include <bits/stdc++.h>

#define int long long

using namespace std;

int kadaneS(const vector<int> &col) {
    int maxSoFar = INT_MIN, maxEndingHere = 0;
    for (auto &i : col) {
        maxEndingHere += i;
        maxSoFar = max(maxSoFar, maxEndingHere);
        maxEndingHere = max(maxEndingHere, (int) 0);
    }
    return maxSoFar;
}

int maxSubMatrix(vector<vector<int>> matrix, int s) {
    int res = 0;
    for (int l = 0; l < s; l++) {
        vector<int> col(s, 0);
        for (int r = l; r < s; r++) {
            for (int i = 0; i < s; i++) {
                col[i] += matrix[i][r];
            }
            res = max(res, kadaneS(col));
        }
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int s, n;
        cin >> s >> n;
        vector<vector<int>> matrix(s, vector<int> (s, 1));
        while (n--) {
            int r1, c1, r2, c2;
            cin >> r1 >> c1 >> r2 >> c2;
            r1--, c1--, r2--, c2--;
            for (int i = r1; i <= r2; i++) {
                for (int j = c1; j <= c2; j++) {
                    matrix[i][j] = INT_MIN;
                }
            }
        }
        cout << maxSubMatrix(matrix, s) << "\n";
    }
    return 0;
}