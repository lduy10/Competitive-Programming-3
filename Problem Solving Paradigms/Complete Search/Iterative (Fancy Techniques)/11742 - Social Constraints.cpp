#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &p, vector<vector<int>> &d) {
    for (int i = 0; i < p.size(); i++) {
        for (int j = 0; j < p.size(); j++) {
            if (d[p[i]][p[j]] > 0 && abs(i - j) > abs(d[p[i]][p[j]])) {
                return false;
            }
            if (d[p[i]][p[j]] < 0 && abs(i - j) < abs(d[p[i]][p[j]])) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, m;
    while (cin >> n >> m, n) {
        vector<vector<int>> d(n, vector<int> (n, 0));
        int a, b, c;
        while (m--) {
            cin >> a >> b >> c;
            d[a][b] = c;
            d[b][a] = c;
        }
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        int ans = 0;
        do {
            if (check(p, d)) {
                ans++;
            }
        } while (next_permutation(p.begin(), p.end()));
        cout << ans << "\n";
    }
    return 0;
}