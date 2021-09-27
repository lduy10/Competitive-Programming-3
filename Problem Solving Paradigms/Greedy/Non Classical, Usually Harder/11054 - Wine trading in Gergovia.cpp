#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        int sum = 0, ans = 0, a;
        while (n--) {
            cin >> a;
            sum += a;
            if (sum < 0) {
                ans -= sum;
            } else {
                ans += sum;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}