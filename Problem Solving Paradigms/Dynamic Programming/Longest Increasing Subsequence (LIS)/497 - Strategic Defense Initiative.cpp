#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    int t, tc = 0;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while (t--) {
        vector<int> a, trace;
        string s;
        int x, n, max = 1;
        while (getline(cin, s), !s.empty()) {
            a.emplace_back(stoi(s));
        }
        n = a.size();
        trace.resize(n);
        for (int i = 0; i < n; i++) {
            trace[i] = i;
        }
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                    if (max < dp[i]) max = dp[i];
                }
            }
        }
        int idx = n - 1;
        while (dp[idx] != max) idx--;
        vector<int> ans;
        while (true) {
            ans.emplace_back(a[idx]);
            if (idx == trace[idx]) break;
            idx = trace[idx];
        }
        reverse(ans.begin(), ans.end());
        if (tc++) cout << "\n";
        cout << "Max hits: " << ans.size() << "\n";
        for (int &i : ans) {
            cout << i << "\n";
        }
    }
    /*fin.close();
    fout.close();*/
    return 0;
}