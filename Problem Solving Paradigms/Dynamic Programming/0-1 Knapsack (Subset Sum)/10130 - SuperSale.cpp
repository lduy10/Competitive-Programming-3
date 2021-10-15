#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n), w(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i] >> w[i];
        }
        vector<vector<int>> dp(n + 1, vector<int> (31));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= 30; j++) {
                if (i == 0 or j == 0) dp[i][j] = 0;
                else if (j < w[i - 1]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + p[i - 1]);
            }
        }
        int g, ans = 0;
        cin >> g;
        while (g--) {
            int mw;
            cin >> mw;
            ans += dp[n][mw];
        }
        cout << ans << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}