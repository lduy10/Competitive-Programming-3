#include <bits/stdc++.h>
 
#define int long long
 
using namespace std;

int dfsTime;
vector<vector<int>> adj;
vector<int> num, low, parent;
vector<pair<int, int>> ans;

void findBridge(int u) {
    num[u] = low[u] = ++dfsTime;
    for (auto &v : adj[u]) {
        if (!num[v]) {
            parent[v] = u;
            findBridge(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) {
                ans.push_back({min(u, v), max(u, v)});
            }
        } else if (v != parent[u]){
            low[u] = min(low[u], num[v]);
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        dfsTime = 0;
        ans.clear();
        adj.assign(n, vector<int> (0));
        num.assign(n, 0);
        low.assign(n, 0);
        parent.assign(n, -1);
        for (int i = 0; i < n; i++) {
            int u;
            string c;
            cin >> u >> c;
            c.pop_back();
            c.erase(c.begin());
            int m = stoi(c);
            for (int j = 0; j < m; j++) {
                int v;
                cin >> v;
                adj[u].push_back(v);
            }
        }
        for (int i = 0; i < n; i++) {
            if (!num[i]) {
                findBridge(i);
            }
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << " critical links\n";
        for (auto &[u, v] : ans) {
            cout << u << " - " << v << "\n";
        }
        cout << "\n";
    }
    return 0;
}