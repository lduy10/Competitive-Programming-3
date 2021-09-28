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
        vector<int> a(n);
        for (int &i : a) {
            cin >> i;
        }
        int ans = 1, tmp = a[0];
        for (int i = 1; i < n; i++) {
            if (ans % 2 != 0) {
                if (a[i] > tmp) {
                    tmp = a[i];
                } else {
                    tmp = a[i];
                    ans++;
                }
            } else {
                if (a[i] > tmp) {
                    tmp = a[i];
                    ans++;
                } else {
                    tmp = a[i];
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}