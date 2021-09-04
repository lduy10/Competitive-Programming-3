#include <bits/stdc++.h>

using namespace std;

map<int, set<char>> m;
vector<string> ans;
string pass;

void backtrack(int p) {
    if (p == 5) {
        ans.emplace_back(pass);
        return;
    }
    for (auto &i : m[p]) {
        pass += i;
        backtrack(p + 1);
        pass.pop_back();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        m.clear();
        ans.assign(1, " ");
        pass.clear();
        map<int, set<char>> m1;
        string r;
        for (int i = 0; i < 6; i++) {
            cin >> r;
            for (int j = 0; j < 5; j++) {
                m1[j].insert(r[j]);
            }
        }
        for (int i = 0; i < 6; i++) {
            cin >> r;
            for (int j = 0; j < 5; j++) {
                if (m1[j].find(r[j]) != m1[j].end()) {
                    m[j].insert(r[j]);
                }
            }
        }
        backtrack(0);
        if (k >= ans.size()) {
            cout << "NO";
        } else {
            cout << ans[k];
        }
        cout << "\n";
    }
    return 0;
}