#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, tc = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int tmp = 0, mx = 0;
        vector<int> a;
        while (n--) {
            int r;
            cin >> r;
            if (r - tmp > mx) mx = r - tmp;
            a.emplace_back(r - tmp);
            tmp = r;
        }
        int ans = mx;
        for (int &i : a) {
            if (mx < i) {
                ans++;
                break;
            }
            if (mx == i) {
                mx--;
            }
        }
        cout << "Case " << tc++ << ": " << ans << "\n";
    }
    return 0;
}