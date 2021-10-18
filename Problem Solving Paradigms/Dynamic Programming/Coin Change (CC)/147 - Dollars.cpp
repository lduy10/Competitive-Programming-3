#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
    vector<int> dp(30001);
    dp[0] = 1;
    for (int i : a) {
        for (int j = i; j <= 30000; j++) {
            dp[j] += dp[j - i];
        }
    }
    double n;
    while (cin >> n, n) {
        printf("%6.2lf%17lld\n", n, dp[(n * 100 + 0.5)]);
    }
    /*fin.close();
    fout.close();*/
    return 0;
}