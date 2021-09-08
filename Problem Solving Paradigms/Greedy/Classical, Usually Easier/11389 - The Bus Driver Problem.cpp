#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d, r;
    while (cin >> n >> d >> r, n) {
        vector<int> morning(n), afternoon(n);
        for (int &i : morning) {
            cin >> i;
        }
        for (int &i : afternoon) {
            cin >> i;
        }
        sort(morning.begin(), morning.end());
        sort(afternoon.begin(), afternoon.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = morning[i] + afternoon[i];
            if (sum > d) {
                ans += (sum - d) * r;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}