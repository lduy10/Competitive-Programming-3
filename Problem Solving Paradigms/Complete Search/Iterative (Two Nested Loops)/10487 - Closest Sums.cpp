#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, tc = 1;
    while (cin >> n, n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int q;
        cin >> q;
        cout << "Case " << tc++ << ":\n";
        while (q--) {
            int ans = a[0] + a[1], s;
            cin >> s;
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (abs(a[i] + a[j] - s) < abs(ans - s)) {
                        ans = a[i] + a[j];
                    }
                }
            }
            cout << "Closest sum to " << s << " is " << ans << ".\n";
        }
    }
    return 0;
}