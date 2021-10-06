#include <bits/stdc++.h>

#define int long long

using namespace std;

int lis(const vector<int> &a) {
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 0;
    while (true) {
        vector<int> a;
        int x;
        while (cin >> x, x != -1) {
            a.emplace_back(x);
        }
        if (a.empty()) break;
        if (tc) cout << "\n";
        cout << "Test #" << ++tc << ":\n  maximum possible interceptions: " << lis(a) << "\n";
    }

    return 0;
}