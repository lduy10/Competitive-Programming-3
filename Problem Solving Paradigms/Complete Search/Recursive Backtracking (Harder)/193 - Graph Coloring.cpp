#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> ans, cur;
vector<vector<int>> adj;
bitset<101> color;

bool canBeBlack(int p) {
    for (int &i : adj[p]) {
        if (color[i]) {
            return false;
        }
    }
    return true;
}

void backtrack(int p) {
    if (ans.size() < cur.size()) {
        ans = cur;
    }
    if (p == n) {
        return;
    }
    int maxBlacks = n - p;
    if (maxBlacks + cur.size() <= ans.size()) {
        return;
    }
    if (canBeBlack(p)) {
        color[p] = true;
        cur.emplace_back(p);
        backtrack(p + 1);
        color[p] = false;
        cur.pop_back();
    }
    backtrack(p + 1);
}

int main() {
    int m;
    cin >> m;
    while (m--) {
        cin >> n >> k;
        ans.clear();
        cur.clear();
        color.reset();
        adj.assign(n, vector<int> (0));
        while (k--) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        backtrack(0);
        cout << ans.size() << "\n";
        for (int &i : ans) {
            cout << i + 1;
            if (i != ans.back()) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}