#include <bits/stdc++.h>

#define int long long

using namespace std;

int n, m, dfsTime;
vector<vector<int>> adj, ans;
vector<int> num, low;

void dfs(int u, int pre) {
    num[u] = low[u] = ++dfsTime;
    for (int &v : adj[u]) {
        if (v != pre) {
            if (!num[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] == num[v]) {
                    ans[u][v] = ans[v][u] = 1;
                } else if (!ans[v][u]) {
                    ans[u][v] = 1;
                }
            } else {
                low[u] = min(low[u], num[v]);
                if (!ans[v][u]) {
                    ans[u][v] = 1;
                }
            }
        }
    }
}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int tc = 1; 
    while (cin >> n >> m, n) {
        dfsTime = 0;
        adj.assign(n + 1, vector<int> (0));
        ans.assign(n + 1, vector<int> (n + 1, 0));
        num.assign(n + 1, 0);
        low.assign(n + 1, 0);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);    
        }
        dfs(1, 1);
        cout << tc++ << "\n\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (ans[i][j]) {
                    cout << i << " " << j << "\n";
                }
            }
        }
        cout << "#\n";
    }
    return 0;
}
