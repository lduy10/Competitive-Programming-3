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
        n--;
        vector<int> a(n);
        for (int &i : a) {
            cin >> i;
        }
        int maxSoFar = INT_MIN, maxEndingHere = 0;
        int l = 0, r = 0, tmp = 0;
        for (int i = 0; i < n; i++) {
            maxEndingHere += a[i];
            if (maxEndingHere == maxSoFar
                && i - tmp > r - l) {
                l = tmp;
                r = i;
            }
            if (maxEndingHere > maxSoFar) {
                l = tmp;
                r = i;
                maxSoFar = maxEndingHere;
            }
            if (maxEndingHere < 0) {
                maxEndingHere = 0;
                tmp = i + 1;
            }
        }
        if (maxSoFar > 0) {
            cout << "The nicest part of route "
                 << tc++ << " is between stops "
                 << l + 1 << " and " << r + 2;
        } else {
            cout << "Route " << tc++ << " has no nice parts";
        }
        cout << '\n';
    }
    return 0;
}