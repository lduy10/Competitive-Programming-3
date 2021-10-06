#include <bits/stdc++.h>

#define int long long

using namespace std;

int lis(const vector<int> &a, const vector<int> &p, int &n) {
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (p[a[j]] < p[a[i]]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int n, x;
    cin >> n;
    while (n) {
        vector<int> a, p(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> x;
            p[i] = x;
        }
        cin.ignore();
        while (getline(cin, s), s.size() > 2) {
            a.resize(n);
            stringstream ss(s);
            for (int i = 1; i <= n; i++) {
                ss >> x;
                a[x - 1] = i;
            }
            cout << lis(a, p, n) << "\n";
        }
        if (s.empty()) n = 0;
        else n = stoi(s);
    }
    return 0;
}