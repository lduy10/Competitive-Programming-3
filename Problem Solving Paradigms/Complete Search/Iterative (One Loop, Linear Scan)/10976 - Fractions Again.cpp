#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    while (cin >> k) {
        vector<pair<int, int>> ans;
        for (int y = k + 1; y <= k * 2; y++) {
            int x = (k * y) / (y - k);
            if (k * y == x * (y - k)) {
                ans.emplace_back(x, y);
            }
        }
        cout << ans.size() << "\n";
        for (auto i : ans) {
            cout << "1/" << k << " = " << "1/" << i.first << " + " << "1/" << i.second << "\n";
        }
    }
    return 0;
}