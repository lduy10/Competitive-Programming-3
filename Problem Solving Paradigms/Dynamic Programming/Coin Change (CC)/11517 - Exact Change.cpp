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
        int p, n;
        cin >> p >> n;
        vector<int> a(n);
        for (int &i : a) {
            cin >> i;
        }
        vector<int> dp(20001, INT_MAX);
        dp[0] = 0;
        for (int &i : a) {
            for (int j = 20000; j >= i; j--) {
                if (dp[j - i] != INT_MAX and dp[j - i] + 1 < dp[j]) {
                    dp[j] = dp[j - i] + 1;
                }
            }
        }
        while (dp[p] == INT_MAX) p++;
        cout << p << " " << dp[p] << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}