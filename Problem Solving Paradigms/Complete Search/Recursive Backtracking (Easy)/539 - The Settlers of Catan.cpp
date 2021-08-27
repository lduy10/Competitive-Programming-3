#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> adj;
int n, m, ans;

void DFS(int root, int length) {
	if (length > ans) {
		ans = length;
	}
	for (int i = 0; i < n; i++) {
		if (adj[root][i]) {
			adj[root][i] = false;
			adj[i][root] = false;
			DFS(i, length + 1);
			adj[root][i] = true;
			adj[i][root] = true;
		}
	}
}

int main() {
	while (cin >> n >> m, n) {
		ans = INT_MIN;
		adj.assign(n, vector<bool> (n, false));
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u][v] = true;
			adj[v][u] = true;
		}
		
		for (int i = 0; i < n; i++) {
			DFS(i, 0);
		}
		cout << ans << "\n";
	}
	return 0;
}
