#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        vector<int> a;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x) a.emplace_back(x);
        }
        if (a.size()) {
            for (int i = 0; i < a.size(); i++) {
                cout << a[i];
                if (i < a.size() - 1) cout << " ";
            }
        } else {
            cout << 0;
        }
        cout << "\n";
    }
    return 0;
}