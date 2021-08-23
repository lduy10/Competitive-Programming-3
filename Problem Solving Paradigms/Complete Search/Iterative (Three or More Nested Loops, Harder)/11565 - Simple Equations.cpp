#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> ans(3, 0);
        for (int x = -100; x <= 100; x++) {
            for (int y = x + 1; y <= 100; y++) {
                int z = sqrt(c - x * x - y * y);
                if (z == y || z == x) continue;
                if (x + y + z == a && x * y * z == b
                    && x * x + y * y + z * z == c
                    && (ans[0] == 0 || ans[1] > y)) {
                    ans[0] = x;
                    ans[1] = y;
                    ans[2] = z;
                }
            }
        }
        if (!ans[0]) {
            cout << "No solution.";
        } else {
            for (int i = 0; i < 3; i++) {
                cout << ans[i];
                if (i < 2) {
                    cout << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}