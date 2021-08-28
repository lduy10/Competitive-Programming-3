#include <bits/stdc++.h>

using namespace std;

vector<string> ans;
string bits;
int n, h;

void backtrack(int p, int cnt) {
    if (cnt == h) {
        string tmp = bits;
        for (int i = p; i < n; i++) {
            tmp += '0';
        }
        ans.emplace_back(tmp);
        return;
    }
    if (p == n) {
        return;
    }
    bits += '0';
    backtrack(p + 1, cnt);
    bits.pop_back();
    bits += '1';
    backtrack(p + 1, cnt + 1);
    bits.pop_back();
}

int main() {
    int t, tc = 0;
    cin >> t;
    while (t--) {
        cin >> n >> h;
        ans.clear();
        if (tc++) {
            cout << "\n";
        }
        backtrack(0, 0);
        for (auto &i : ans) {
            cout << i << "\n";
        }
    }
}