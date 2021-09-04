#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d, i, ans = 1;
        cin >> d >> i;
        d--;
        while (d--) {
            if (i % 2) {
                ans *= 2;
                i = (i + 1) / 2;
            } else {
                ans = ans * 2 + 1;
                i /= 2;
            }
        }
        cout << ans << "\n";
    }
    cin >> t;
    return 0;
}