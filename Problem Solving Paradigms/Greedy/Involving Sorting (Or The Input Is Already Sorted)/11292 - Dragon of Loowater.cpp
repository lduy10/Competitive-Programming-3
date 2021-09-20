#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m, n) {
        vector<int> heads(n);
        for (int &i : heads) {
            cin >> i;
        }
        multiset<int> heights;
        while (m--) {
            int height;
            cin >> height;
            heights.insert(height);
        }
        bool ok = true;
        int ans = 0;
        for (int &head : heads) {
            auto p = heights.lower_bound(head);
            if (p == heights.end()) {
                ok = false;
                break;
            } else {
                ans += *p;
                heights.erase(heights.find(*p));
            }
        }
        if (ok) {
            cout << ans;
        } else {
            cout << "Loowater is doomed!";
        }
        cout << "\n";
    }
    return 0;
}