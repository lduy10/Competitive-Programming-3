#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int>> p(1000001);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            p[x].emplace_back(i);
        }
        while (m--) {
            int k, v;
            cin >> k >> v;
            if (k > p[v].size()) {
                cout << 0;
            } else {
                cout << p[v][k - 1];
            }
            cout << "\n";
        }
    }
    return 0;
}