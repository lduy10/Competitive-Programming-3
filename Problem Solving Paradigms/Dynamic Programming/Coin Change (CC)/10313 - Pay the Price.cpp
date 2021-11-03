#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> dp(301, vector<int>(301));
    dp[0][0] = 1;
    for (int i = 1; i <= 300; i++) {
        for (int j = i; j <= 300; j++) {
            for (int k = 1; k <= j; k++) {
                dp[j][k] += dp[j - i][k - 1];
            }
        }
    }
    string s;
    while (getline(cin, s)) {
        stringstream ss(s);
        vector<int> a;
        int x;
        while (ss >> x) {
            a.emplace_back(x);
        }
        int ans = 0, start, end;
        if (a.size() == 1) {
            start = 0, end = a[0];
        } else if (a.size() == 2) {
            start = 0, end = a[1];
        } else {
            start = a[1], end = a[2];
        }
        if (end > a[0]) end = a[0];
        for (int i = start; i <= end; i++) {
            ans += dp[a[0]][i];
        }
        cout << ans << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}