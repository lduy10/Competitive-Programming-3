#include <bits/stdc++.h>

#define int long long

using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

int DFS(pair<int, int> pos, vector<vector<char>> &a, vector<vector<bool>> &visited, int r, int c) {
    int x0 = pos.first, y0 = pos.second;
    visited[x0][y0] = true;
    int ans = 1;
    for (int i = 0; i < 4; i++) {
        int x1 = x0 + dx[i], y1 = y0 + dy[i];
        if (x1 < 0 || x1 >= r || y1 < 0 || y1 >= c) continue;
        if (!visited[x1][y1] && a[x1][y1] == '0') {
            ans += DFS({x1, y1}, a, visited, r, c);
        }
    }
    return ans;
}

int32_t main() {
    /* ifstream fin("input.txt");
     ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, tc = 0;
    cin >> m;
    while (m--) {
        pair<int, int> pos;
        cin >> pos.first >> pos.second;
        pos.first--, pos.second--;
        cin.ignore();
        vector<vector<char>> a;
        string row;
        int r = 0, c;
        while (getline(cin, row), !row.empty()) {
            c = row.size();
            a.emplace_back(vector<char>(c));
            for (int i = 0; i < c; i++) {
                a[r][i] = row[i];
            }
            r++;
        }
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        if (tc++) cout << "\n";
        cout << DFS(pos, a, visited, r, c) << "\n";
    }
    return 0;
}
