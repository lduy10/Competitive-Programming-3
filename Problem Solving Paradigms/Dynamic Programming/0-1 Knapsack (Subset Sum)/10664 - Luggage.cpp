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
    string s;
    getline(cin, s);
    while (t--) {
        getline(cin, s);
        stringstream ss(s);
        int x, sum = 0;
        vector<int> a;
        while (ss >> x) {
            a.emplace_back(x);
            sum += x;
        }
        int n = a.size();
        vector<vector<int>> dp(n + 1, vector<int>((sum >> 1) + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= (sum >> 1); j++) {
                if (i == 0 or j == 0) {
                    dp[i][j] = 0;
                } else if (j < a[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + a[i - 1]);
                }
            }
        }
        if (sum % 2 == 0) {
            if (dp[n][sum >> 1] == (sum >> 1)) cout << "YES";
            else cout << "NO";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}