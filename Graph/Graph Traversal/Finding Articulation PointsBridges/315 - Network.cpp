#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxN = 10010;

int n, dfsTime;
vector<vector<int>> adj;
vector<int> num, low;
vector<bool> joint;

void dfs(int u, int pre) {
    num[u] = low[u] = ++dfsTime;
    int childs = 0;
    for (int &v : adj[u]) {
        if (v == pre) {
            continue;
        }
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            childs++;
            if (u == pre) {
                if (childs > 1) {
                    joint[u] = true;
                }
            } else if (low[v] >= num[u]) {
                joint[u] = true;
            }
        } else {
            low[u] = min(low[u], num[v]);
        }
    }
}



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);  
    while (cin >> n, n) {
        cin.ignore();
        dfsTime = 0;
        adj.assign(n + 1, vector<int> (0));
        num.assign(n + 1, 0);
        low.assign(n + 1, 0);
        joint.assign(n + 1, false);
        string s;
        while (getline(cin, s), s != "0") {
            stringstream ss(s);
            int u, v;
            ss >> u;
            while (ss >> v) {
                adj[u].emplace_back(v);
                adj[v].emplace_back(u);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (!num[i]) {
                dfs(i, i);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (joint[i]) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
