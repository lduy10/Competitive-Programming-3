#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == m && m == 0) {
            break;
        }
        map<int, int> M;
        int ans = 0;
        for (int i = 0; i < n + m; i++) {
            int x;
            cin >> x;
            M[x]++;
            if (M[x] > 1) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
