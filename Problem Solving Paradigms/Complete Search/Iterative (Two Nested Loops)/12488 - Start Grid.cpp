#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> s(n + 1), f(n + 1);
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            s[x] = i;
        }
        for (int i = 1; i <= n; i++) {
            cin >> f[i];
        }
        int ans = 0;
        for (int i = 1; i <= n - 1; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (s[f[i]] > s[f[j]]) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}