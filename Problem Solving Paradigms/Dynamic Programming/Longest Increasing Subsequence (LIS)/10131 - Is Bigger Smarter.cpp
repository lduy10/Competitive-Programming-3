#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int w, s;
    vector<tuple<int, int, int>> a;
    while (cin >> w >> s) {
        a.emplace_back(w, s, a.size() + 1);
    }
    int n = a.size();
    vector<int> dp(n, 1), trace(n);
    for (int i = 0; i < n; i++) {
        trace[i] = i;
    }
    sort(a.begin(), a.end());
    int maxIndex = 0, mx = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (get<0>(a[j]) < get<0>(a[i])
            and get<1>(a[j]) > get<1>(a[i])
            and dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                trace[i] = j;
                if (mx < dp[i]) {
                    maxIndex = i;
                    mx = dp[i];
                }
            }
        }
    }
    vector<tuple<int, int, int>> ans;
    while (true) {
        ans.emplace_back(a[maxIndex]);
        if (maxIndex == trace[maxIndex]) break;
        maxIndex = trace[maxIndex];
    }
    cout << mx << "\n";
    for (int i = mx - 1; i >= 0; i--) {
        cout << get<2>(ans[i]) << "\n";
    }
    /*fin.close();
    fout.close();*/
    return 0;
}