#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {1, 5, 10, 25, 50};
    vector<int> dp(7490);
    dp[0] = 1;
    for (int i : a) {
        for (int j = i; j <= 7489; j++) {
            dp[j] += dp[j - i];
        }
    }
    int n;
    while (cin >> n) {
        cout << dp[n] << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}