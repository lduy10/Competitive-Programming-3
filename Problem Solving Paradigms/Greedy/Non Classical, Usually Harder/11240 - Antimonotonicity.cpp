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
        int x, tmp;
        cin >> tmp;
        n--;
        int ans = 1;
        while (n--) {
            cin >> x;
            if (ans % 2 != 0) {
                if (x > tmp) {
                    tmp = x;
                } else {
                    tmp = x;
                    ans++;
                }
            } else {
                if (x > tmp) {
                    tmp = x;
                    ans++;
                } else {
                    tmp = x;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}