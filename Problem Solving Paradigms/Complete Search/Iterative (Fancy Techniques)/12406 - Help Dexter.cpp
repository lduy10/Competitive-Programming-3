#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, tc = 1;
    cin >> t;
    while (t--) {
        int p, q;
        cin >> p >> q;
        vector<long long> ans;
        for (int i = 0; i < (1 << p); i++) {
            long long sum = 0;
            for (int j = 0; j < p; j++) {
                if (i & (1 << j)) {
                    sum = sum * 10 + 2;
                } else {
                    sum = sum * 10 + 1;
                }
            }
            if (sum % (1 << q) == 0) {
                ans.emplace_back(sum);
            }
        }
        cout << "Case " << tc++ << ": ";
        if (ans.empty()) {
            cout << "impossible";
        } else {
            cout << ans[0];
            if (ans[ans.size() -  1] != ans[0]) {
                cout << " " << ans[ans.size() -  1];
            }
        }
        cout << "\n";
    }
    return 0;
}