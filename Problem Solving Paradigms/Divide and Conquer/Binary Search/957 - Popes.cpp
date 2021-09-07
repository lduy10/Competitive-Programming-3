#include <bits/stdc++.h>
using namespace std;

int main() {
    int y;
    while (cin >> y) {
        pair<int, int> ans;
        int p;
        cin >> p;
        vector<int> a(p);
        for (int &i : a) {
            cin >> i;
        }
        int mx = INT_MIN;
        for (int i = 0; i < p; i++) {
            int cur = a[i];
            int pre = cur - y + 1;
            int j = lower_bound(a.begin(), a.end(), pre) - a.begin();
            if (i - j + 1 > mx) {
                mx = i - j + 1;
                ans.first = a[j], ans.second = cur;
            }
        }
        cout << mx << " " << ans.first << " " << ans.second << "\n";
    }
    return 0;
}