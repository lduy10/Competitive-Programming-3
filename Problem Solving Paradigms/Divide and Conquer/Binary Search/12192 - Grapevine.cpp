#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, tc = 1;
    while (cin >> n >> m, n) {
        map<int, vector<int>> diagonals;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int h;
                cin >> h;
                int d = i - j;
                diagonals[d].emplace_back(h);
            }
        }
        int q;
        cin >> q;
        while (q--) {
            int ans = 0;
            int l, u;
            cin >> l >> u;
            for (auto &i : diagonals) {
                auto s = lower_bound(i.second.begin(), i.second.end(), l);
                if (s == i.second.end()) continue;
                int x = s - i.second.begin(), y;
                if (x == 0 && i.second[x] > u) continue;
                auto e = upper_bound(i.second.begin(), i.second.end(), u);
                if (e == i.second.end()) {
                    y = i.second.size() - 1;
                } else {
                    y = e - i.second.begin() - 1;
                }
                if (ans < y - x + 1) {
                    ans = y - x + 1;
                }
            }
            cout << ans << "\n";
        }
        cout << "-\n";
    }
    return 0;
}