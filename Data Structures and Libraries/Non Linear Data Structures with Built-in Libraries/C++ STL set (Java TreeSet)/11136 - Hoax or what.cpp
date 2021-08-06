#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        set<int> s;
        map<int, int> m;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                m[x]++;
                s.insert(x);
            }
            auto maxBill = --s.end();
            auto minBill = s.begin();
            ans += *maxBill - *minBill;
            m[*maxBill]--;
            m[*minBill]--;
            if (!m[*maxBill]) {
                s.erase(*maxBill);
            }
            if (!m[*minBill]) {
                s.erase(*minBill);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}