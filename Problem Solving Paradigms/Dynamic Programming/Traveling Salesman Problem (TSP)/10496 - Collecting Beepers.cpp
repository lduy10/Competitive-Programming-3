#include <bits/stdc++.h>

#define int long long

using namespace std;

int n;
vector<int> x, y;
vector<vector<int>> dist, dp;

int tsp(int p, int mask) {
    if (mask == (1 << (n + 1)) - 1) {
        return dist[p][0];
    }
    if (dp[p][mask] != -1) {
        return dp[p][mask];
    }
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++) {
        if (i != p && !(mask & (1 << i))) {
            ans = min(ans, dist[p][i] + tsp(i, mask | (1 << i)));
        }
    }
    return dp[p][mask] = ans;
}

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int r, c, s, e;
        cin >> r >> c >> s >> e >> n;
        x.resize(n + 1);
        y.resize(n + 1);
        x[0] = s, y[0] = e;
        for (int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }
        dist.assign(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int d = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                dist[i][j] = d;
                dist[j][i] = d;
            }
        }
        dp.assign(n + 1, vector<int>(1 << 11, -1));
        cout << "The shortest path has length " << tsp(0, 1) << "\n";
    }
  /*  fin.close();
    fout.close();*/
    return 0;
}
