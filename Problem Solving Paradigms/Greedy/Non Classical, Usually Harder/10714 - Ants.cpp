#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int l, n;
        cin >> l >> n;
        int mx = -1, mn = -1;
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            int rd = l - p;
            if (p < rd) {
                mx = max(mx, rd);
                mn = max(mn, p);
            } else {
                mx = max(mx, p);
                mn = max(mn, rd);
            }
        }
        cout << mn << " " << mx << "\n";
    }
    return 0;
}