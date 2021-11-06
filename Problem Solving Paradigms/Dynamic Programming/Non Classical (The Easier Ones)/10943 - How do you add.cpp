#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /* ifstream fin("input.txt");
     ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> dp(101, vector<int> (101, 0));
    for (int i = 0; i <= 100; i++) {
        dp[i][1] = 1;
    }
    for (int i = 0; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 0; k <= i; k++) {
                dp[i][j] = (dp[i][j] + dp[i - k][j - 1]) % 1000000;
            }
        }
    }
    int n, k;
    while (cin >> n >> k, n && k) {
        cout << dp[n][k] << "\n";
    }
    return 0;
}

