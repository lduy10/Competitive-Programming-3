#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[] = {1, 5, 10, 25, 50};
    vector<int> dp(30001);
    dp[0] = 1;
    for (int i : a) {
        for (int j = i; j <= 30000; j++) {
            dp[j] += dp[j - i];
        }
    }
    int n;
    while (cin >> n) {
        int ans = dp[n];
        if (ans > 1) {
            cout << "There are " << ans << " ways to produce " << n << " cents change.";
        } else {
            cout << "There is only 1 way to produce " << n << " cents change.";
        }
        cout << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}