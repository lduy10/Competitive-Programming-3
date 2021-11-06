#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /* ifstream fin("input.txt");
     ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, t;
    while (cin >> m >> n >> t) {
        vector<int> dp(t + 1);
        vector<int> cnt(t + 1);
        if (m > n) swap(m, n);
        if (m > t) {
            cout << 0 << " " << t << "\n";
            continue;
        }
        dp[m] = m;
        cnt[m] = 1;
        for (int i = m + 1; i <= t; i++) {
            dp[i] = dp[i - m] + m;
            cnt[i] = cnt[i - m] + 1;
            if (i >= n) {
                if (dp[i] < dp[i - n] + n) {
                    dp[i] = dp[i - n] + n;
                    cnt[i] = cnt[i - n] + 1;
                }
            }
        }
        cout << cnt[t];
        if (dp[t] < t) {
            cout << " " << t - dp[t];
        }
        cout << "\n";
    }
    return 0;
}



