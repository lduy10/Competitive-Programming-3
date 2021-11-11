#include <bits/stdc++.h>

#define int long long

using namespace std;

int DFS(int p, vector<int> &adj, vector<bool> &visited, vector<int> &dp) {
    dp[p] = 0;
    visited[p] = true;
    if (!visited[adj[p]]) {
        dp[p] += (DFS(adj[p], adj, visited, dp) + 1);
    }
    visited[p] = false;
    return dp[p];
}

int32_t main() {
    /* ifstream fin("input.txt");
     ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, tc = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> adj(n + 1);
        for (int i = 0; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u] = v;
        }
        int ans = 0, mx = 0;
        vector<bool> visited(n + 1, false);
        vector<int> dp(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (dp[i] == -1) {
                int length = DFS(i, adj, visited, dp);
                if (length > mx) {
                    ans = i;
                    mx = length;
                }
            }
        }
        cout <<  "Case " << tc++ << ": " << ans << "\n";
    }
    return 0;
}
