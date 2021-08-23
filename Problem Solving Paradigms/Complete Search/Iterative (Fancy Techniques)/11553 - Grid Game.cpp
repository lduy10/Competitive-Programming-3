#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int> (n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        int ans = INT_MAX;
        do {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                sum += grid[i][p[i]];
            }
            if (sum < ans) ans = sum;
        } while (next_permutation(p.begin(), p.end()));
        cout << ans << "\n";
    }
    return 0;
}