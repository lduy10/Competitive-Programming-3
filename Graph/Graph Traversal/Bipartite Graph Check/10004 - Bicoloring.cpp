#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n, n) {
        cin >> m;
        vector<vector<int>> adj(n);
        vector<int> color(n, -1);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        queue<int> q;
        color[0] = 0;
        bool isBipartite = true;
        q.push(0);
        while (!q.empty() && isBipartite) {
            int u = q.front();
            q.pop();
            for (int &v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    isBipartite = false;
                    break;
                }
            }
        }
        if (isBipartite) {
            cout << "BICOLORABLE.";
        } else {
            cout << "NOT BICOLORABLE.";
        }
        cout << "\n";
    }
    return 0;
}