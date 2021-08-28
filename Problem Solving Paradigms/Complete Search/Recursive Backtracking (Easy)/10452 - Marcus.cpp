#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> path;
vector<string> ans;
int dx[] = {0, -1, 0};
int dy[] = {-1, 0, 1};
int m, n;

void backtrack(int x, int y) {
    if (path[x][y] == '#') {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i < ans.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < 3; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if (x1 >= m || x1 < 0 || y1 >= n || y1 < 0) continue;
        if (path[x1][y1] == 'I' || path[x1][y1] == 'E'
            || path[x1][y1] == 'H' || path[x1][y1] == 'O'
            || path[x1][y1] == 'V' || path[x1][y1] == 'A'
            || path[x1][y1] == '#') {
            if (!ans.empty()) {
                if ((ans.back() == "left" && i == 2)
                    || (ans.back() == "right" && i == 0))
                    continue;
            }
            if (i == 0) {
                ans.emplace_back("left");
            } else if (i == 1) {
                ans.emplace_back("forth");
            } else {
                ans.emplace_back("right");
            }
            backtrack(x1, y1);
            ans.pop_back();
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> m >> n;
        int x0, y0;
        path.assign(m, vector<char>(n));
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++) {
                path[i][j] = s[j];
                if (s[j] == '@') {
                    x0 = i, y0 = j;
                }
            }
        }
        backtrack(x0, y0);
    }
    return 0;
}