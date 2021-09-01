#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> adj;
vector<int> ans;
vector<bool> visited;

bool backtrack(int p) {
    if (ans.size() == n + 1 && ans.back() == 1) {
        return true;
    }
    for (int &i : adj[p]) {
        if ((ans.size() == n && i == 1) || !visited[i]) {
            visited[i] = true;
            ans.emplace_back(i);
            if (backtrack(i)) return true;
            visited[i] = false;
            ans.pop_back();
        }
    }
    return false;
}

int main() {
    while (cin >> n) {
        cin.ignore();
        adj.assign(n + 1, vector<int>(0));
        ans.assign(1, 1);
        visited.assign(n + 1, false);
        string edge;
        while (getline(cin, edge), edge != "%") {
            stringstream ss(edge);
            int u, v;
            ss >> u >> v;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        visited[1] = true;
        if (!backtrack(1)) {
            cout << "N";
        } else {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i];
                if (i < ans.size() - 1) {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}