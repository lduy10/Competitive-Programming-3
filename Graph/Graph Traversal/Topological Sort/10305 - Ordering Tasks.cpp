#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> ans;

void DFS(int p, vector<bool> &visited, vector<vector<int>> &adj) {
    for (int &i : adj[p]) {
        if (!visited[i]) {
            visited[i] = true;
            DFS(i, visited, adj);
        }
    }
    ans.emplace_back(p);
}

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    while (cin >> n >> m, n) {
        ans.clear();
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj[u - 1].emplace_back(v - 1);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                visited[i] = true;
                DFS(i, visited, adj);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            cout << ans[i] + 1;
            if (i > 0) cout << " ";
        }
        cout << "\n";
    }
    return 0;
}