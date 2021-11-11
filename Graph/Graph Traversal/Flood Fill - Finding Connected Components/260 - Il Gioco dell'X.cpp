#include <bits/stdc++.h>

#define int long long

using namespace std;

int dx[] = {-1, -1, 0, 0, 1, 1};
int dy[] = {-1, 0, -1, 1, 0, 1};

int32_t main() {
    /* ifstream fin("input.txt");
     ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, tc = 1;
    while (cin >> n, n) {
        char a[n][n];
        bool visited[n][n];
        for (int i = 0; i < n; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < n; j++) {
                a[i][j] = row[j];
                visited[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[0][i] && a[0][i] == 'b') {
                queue<pair<int, int>> q;
                q.push({0, i});
                visited[0][i] = true;
                while (!q.empty()) {
                    auto[x0, y0] = q.front();
                    q.pop();
                    for (int j = 0; j < 6; j++) {
                        int x1 = x0 + dx[j];
                        int y1 = y0 + dy[j];
                        if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= n) continue;
                        if (!visited[x1][y1] && a[x1][y1] == 'b') {
                            visited[x1][y1] = true;
                            q.push({x1, y1});
                        }
                    }
                }
            }
        }
        int blackWin = false;
        for (int i = 0; i < n; i++) {
            if (a[n - 1][i] == 'b' && visited[n - 1][i]) {
                blackWin = true;
                break;
            }
        }
        cout << tc++ << " ";
        if (blackWin) {
            cout << "B";
        } else {
            cout << "W";
        }
        cout << "\n";
    }
    return 0;
}
