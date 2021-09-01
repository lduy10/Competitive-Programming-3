#include <bits/stdc++.h>

using namespace std;

vector<int> cnt;
vector<string> ans;
string a, b;
int n, k;
char e[4] = {'A', 'G', 'C', 'T'};

void backtrack(int p) {
    if (p == n) {
        int dif = 0;
        int ok = 0;
        vector<int> cnt1(127, 0);
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) {
                ok++;
            }
        }
        for (char &i : b) {
            cnt1[i]++;
        }
        for (char &i : e) {
            if (cnt[i] < cnt1[i]) {
                dif += cnt1[i] - cnt[i];
            }
        }
        if (dif <= k && ok >= n - k) {
            ans.emplace_back(b);
        }
        return;
    }
    for (char &i : e) {
        b += i;
        backtrack(p + 1);
        b.pop_back();
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        b.clear();
        cnt.assign(127, 0);
        ans.clear();
        cin >> n >> k >> a;
        for (char &i : a) {
            cnt[i]++;
        }
        backtrack(0);
        sort(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto &i : ans) {
            cout << i << "\n";
        }
    }
    return 0;
}