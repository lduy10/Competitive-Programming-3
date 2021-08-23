#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        vector<int> v(n);
        for (int &i : v) {
            cin >> i;
        }
        map<int, pair<int, int>> sum, dif;
        sort(v.begin(), v.end());
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                sum[v[i] + v[j]] = {v[i], v[j]};
            }
        }
        for (int i = n - 1; i >= 1; i--) {
            for (int j = i - 1; j >= 0; j--) {
                dif[v[i] - v[j]] = {v[i], v[j]};
                dif[v[j] - v[i]] = {v[j], v[i]};
            }
        }
        int ans = INT_MIN;
        for (auto &i : sum) {
            auto j = dif.find(i.first);
            if (j != dif.end()) {
                if (i.second.first != j->second.first
                && i.second.first != j->second.second
                && i.second.second != j->second.first
                && i.second.second != j->second.second) {
                    if (ans < j->second.first) {
                        ans = j->second.first;
                    }
                }
            }
        }
        if (ans == INT_MIN) {
            cout << "no solution";
        } else {
            cout << ans;
        }
        cout << "\n";
    }
    return 0;
}