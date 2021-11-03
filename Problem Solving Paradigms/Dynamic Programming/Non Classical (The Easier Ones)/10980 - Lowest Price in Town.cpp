#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
/*    ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    double price;
    int m, tc = 1;
    while (cin >> price >> m) {
        vector<pair<int, double>> a(m);
        for (auto &[n, p] : a) {
            cin >> n >> p;
        }
        string k;
        cin.ignore();
        getline(cin, k);
        stringstream ss(k);
        int x;
        vector<double> dp(101);
        dp[0] = 0;
        for (int i = 1; i <= 100; i++) {
            dp[i] = price * i;
        }
        for (auto &[n, p] : a) {
            for (int i = 0; i <= 100 - n; i++) {
                for (int j = 1; j <= n; j++) {
                    dp[i + j] = min(dp[i + j], dp[i] + p);
                }
            }
        }
        printf("Case %d:\n", tc++);
        while (ss >> x) {
            printf("Buy %d for $%.2lf\n", x, dp[x]);
        }
    }
/*    fin.close();
    fout.close();*/
    return 0;
}
