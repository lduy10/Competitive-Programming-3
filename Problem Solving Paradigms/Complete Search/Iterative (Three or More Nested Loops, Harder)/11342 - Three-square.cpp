#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool solve = false;
        for (int i = 0; i * i + i * i + i * i <= n && !solve; i++) {
            for (int j = i; j * j + i * i + i * i <= n && !solve; j++) {
                for (int k = j; j * j + i * i + k * k <= n; k++) {
                    if (i * i + j * j + k * k == n) {
                        cout << i << " " << j << " " << k;
                        solve = true;
                        break;
                    }
                }
            }
        }
        if (!solve) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}