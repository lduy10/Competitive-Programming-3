#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, tc = 1;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int sz = s.size();
        int ans = 0;
        for (int i = sz - 1; i >= 1; i--) {
            for (int j = i - 1; j >= 0 && j >= i - k; j--) {
                if (s[i] == s[j]) {
                    ans++;
                    break;
                }
            }
        }
        cout << "Case " << tc++ << ": " << ans << '\n';
    }
    return 0;
}