#include <bits/stdc++.h>

using namespace std;

string str;
int n, m, sz;
vector<string> w, r, ans;

void backtrack(int p) {
    if (p == sz) {
        for (auto &i : ans) {
            cout << i;
        }
        cout << "\n";
        return;
    }
    if (str[p] == '#') {
        for (string &i : w) {
            ans.emplace_back(i);
            backtrack(p + 1);
            ans.pop_back();
        }
    } else {
        for (int i = 0; i <= 9; i++) {
            ans.emplace_back(to_string(i));
            backtrack(p + 1);
            ans.pop_back();
        }
    }
}

int main() {
    while (cin >> n) {
        ans.clear();
        w.resize(n);
        for (string &i : w) {
            cin >> i;
        }
        cin >> m;
        r.resize(m);
        for (string &i : r) {
            cin >> i;
        }
        cout << "--\n";
        for (string &i : r) {
            sz = i.size();
            str = i;
            backtrack(0);
        }
    }
    return 0;
}