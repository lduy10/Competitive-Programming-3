#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, tc = 1;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long long ans =  LONG_LONG_MIN;
        for (int i = 0; i < n; i++) {
            long long product = v[i];
            if (product > ans) {
                ans = product;
            }
            for (int j = i + 1; j < n; j++) {
                product *= v[j];
                if (product > ans) {
                    ans = product;
                }
            }
        }
        if (ans < 0) ans = 0;
        cout << "Case #" << tc++ <<": The maximum product is " << ans << ".\n\n";
    }
    return 0;
}