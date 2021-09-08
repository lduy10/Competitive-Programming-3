#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> coins(n);
        for (int &i : coins) {
            cin >> i;
        }
        int ans = 1, sum = 0;
        for (int i = 0; i < n - 1; i++) {
            if(sum + coins[i] < coins[i + 1]) {
                ans++;
                sum += coins[i];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}