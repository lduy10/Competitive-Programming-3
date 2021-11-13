#include <bits/stdc++.h>

#define int long long

using namespace std;

int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

int32_t main() {
    /* ifstream fin("input.txt");
     ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tc = 1;
    while (cin >> n) {
        char a[n][n];
        bool visited[n][n];
        for (int i = 0; i < n; i++) {
            string r;
            cin >> r;
            for (int j = 0; j < n; j++) {
                a[i][j] = r[j];
                visited[i][j] = false;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && a[i][j] == '1') {
                    visited[i][j] = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto[x0, y0] = q.front();
                        q.pop();
                        for (int k = 0; k < 8; k++) {
                            int x1 = x0 + dx[k];
                            int y1 = y0 + dy[k];
                            if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) continue;
                            if (a[x1][y1] == '1' && !visited[x1][y1]) {
                                visited[x1][y1] = true;
                                q.push({x1, y1});
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        cout << "Image number " << tc++ << " contains " << ans << " war eagles.\n";
    }
    return 0;
}
