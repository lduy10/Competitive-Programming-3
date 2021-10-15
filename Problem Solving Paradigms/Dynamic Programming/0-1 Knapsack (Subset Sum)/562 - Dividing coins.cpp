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
        int n, sum = 0;
        cin >> n;
        vector<int> val(n);
        for (int &i : val) {
            cin >> i;
            sum += i;
        }
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0 or j == 0) {
                    dp[i][j] = 0;
                }
                else if (j < val[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - val[i - 1]] + val[i - 1]);
                }
            }
        }
        cout << sum - 2 * dp[n][sum / 2] << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}