#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int &i : a) cin >> i;
        vector<int> lr(n, 1), rl(n, 1), b;
        for (int i = 0; i < n; i++) {
            int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if (idx == b.size()) {
                b.emplace_back(a[i]);
            } else {
                b[idx] = a[i];
            }
            lr[i] = idx + 1;
        }
        b.clear();
        for (int i = n - 1; i >= 0; i--) {
            int idx = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            if (idx == b.size()) {
                b.emplace_back(a[i]);
            } else {
                b[idx] = a[i];
            }
            rl[i] = idx + 1;
        }
        int mx = 1;
        for (int i = 0; i < n; i++) {
            int length = min(lr[i], rl[i]) * 2 - 1;
            mx = max(mx, length);
        }
        cout << mx << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}