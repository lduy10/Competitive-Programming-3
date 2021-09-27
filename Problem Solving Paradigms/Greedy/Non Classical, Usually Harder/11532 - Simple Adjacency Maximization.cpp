#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int p, q;
        cin >> p >> q;
        int ans = 0, i = 0;
        while (p > 0 && q > 0) {
            ans |= ((int) 1 << i);
            p--;
            i++;
            if (!p) break;
            q--;
            i++;
            ans |= ((int) 1 << i);
            p--;
            i++;
        }
        while (p--) {
            ans <<= (int) 1;
            ans |= (int) 1;
        }
        cout << ans << "\n";
    }
    return 0;
}