#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> chimps(n);
        for (int &i : chimps) {
            cin >> i;
        }
        int q;
        cin >> q;
        while (q--) {
            int h;
            cin >> h;
            auto l = lower_bound(chimps.begin(), chimps.end(), h);
            int p1 = l - chimps.begin() - 1;
            (l == chimps.begin()) ? cout << "X" : cout << chimps[p1];
            cout << " ";
            auto r = upper_bound(chimps.begin(), chimps.end(), h);
            int p2 = r - chimps.begin();
            (r == chimps.end()) ? cout << "X" : cout << chimps[p2];
            cout << "\n";
        }
    }
    return 0;
}