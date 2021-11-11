#include <bits/stdc++.h>

#define int long long

using namespace std;

void DFS(int p, vector<vector<int>> &adj, vector<int> &trace) {
    for (int &i : adj[p]) {
        if (trace[i] == -1) {
            trace[i] = p;
            DFS(i, adj, trace);
        }
    }
}

int32_t main() {
    /* ifstream fin("input.txt");
     ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        int u;
        vector<vector<int>> adj(n + 1);
        vector<int> trace(n + 1);
        while (cin >> u, u) {
            int v;
            while (cin >> v, v) {
                adj[u].emplace_back(v);
            }
        }
        int m;
        cin >> m;
        vector<int> startVertices(m);
        for (int &i : startVertices) cin >> i;
        for (int &v : startVertices) {
            trace.assign(n + 1, -1);
            DFS(v, adj, trace);
            vector<int> ans;
            for (int i = 1; i <= n; i++) {
                if (trace[i] == -1) {
                    ans.emplace_back(i);
                }
            }
            cout << ans.size();
            for (int &i : ans) {
                cout << " " << i;
            }
            cout << "\n";
        }
    }
    return 0;
}



