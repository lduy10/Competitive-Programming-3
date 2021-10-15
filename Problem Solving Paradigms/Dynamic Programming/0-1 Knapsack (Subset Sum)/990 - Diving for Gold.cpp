#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, tc = 0, w, n;
    while (cin >> t >> w) {
        cin >> n;
        vector<int> val(n), d(n), wt(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i] >> val[i];
            wt[i] = 3 * d[i] * w;
        }
        vector<vector<int>> dp(n + 1, vector<int> (t + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                if (i == 0 or j == 0) {
                    dp[i][j] = 0;
                } else if (j - wt[i - 1] < 0) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
                }
            }
        }
        vector<int> ans;
        int tmp = t;
        for (int i = n; i > 0; i--) {
            if (dp[i][tmp] != dp[i - 1][tmp]) {
                ans.emplace_back(i - 1);
                tmp -= wt[i - 1];
            }
        }
        if (tc++) cout << "\n";
        cout << dp[n][t] << "\n" << ans.size() << "\n";
        for (int i = ans.size() - 1; i >= 0; i--) {
            cout << d[ans[i]] << " " << val[ans[i]] << "\n";
        }
    }
    /*fin.close();
    fout.close();*/
    return 0;
}