#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, tc = 1;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> a;
        a.emplace_back(0);
        a.emplace_back(d);
        for (int i = 0; i < n; i++) {
            char c, c1;
            int num;
            cin >> c >> c1 >> num;
            a.emplace_back(num);
            if (c == 'B') {
                a.emplace_back(num);
            }
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 2; i < a.size(); i += 2) {
            ans = max(ans, a[i] - a[i - 2]);
        }
        for (int i = 3; i < a.size(); i += 2) {
            ans = max(ans, a[i] - a[i - 2]);
        }
        cout << "Case " << tc++ << ": " << ans << "\n";
    }
    return 0;
}