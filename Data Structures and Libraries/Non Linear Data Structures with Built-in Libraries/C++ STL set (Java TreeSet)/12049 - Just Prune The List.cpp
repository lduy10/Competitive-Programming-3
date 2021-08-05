#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        set<int> mySet;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mySet.insert(a[i]);
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            mySet.insert(b[i]);
        }
        int ans = 0;
        for (auto &i : mySet) {
            ans += abs(count(a.begin(), a.end(), i) - count(b.begin(), b.end(), i));
        }
        cout << ans << "\n";
    }
    return 0;
}
