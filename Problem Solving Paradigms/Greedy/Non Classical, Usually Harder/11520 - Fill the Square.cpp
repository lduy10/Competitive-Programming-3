#include <bits/stdc++.h>

#define int long long

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, tc = 1;
    cin >> t;
    while (t--) {
        vector<bool> used(127, false);
        int n;
        cin >> n;
        vector<vector<char>> square(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            string r;
            cin >> r;
            for (int j = 0; j < n; j++) {
                square[i][j] = r[j];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (square[i][j] != '.') continue;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= n || x < 0
                        || y >= n || y < 0)
                        continue;
                    if (square[x][y] != '.') {
                        used[square[x][y]] = true;
                    }
                }
                for (int k = 65; k <= 90; k++) {
                    if (!used[k]) {
                        square[i][j] = k;
                        break;
                    }
                }
                for (int k = 65; k <= 90; k++) {
                    used[k] = false;
                }
            }
        }
        cout << "Case " << tc++ << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << square[i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}