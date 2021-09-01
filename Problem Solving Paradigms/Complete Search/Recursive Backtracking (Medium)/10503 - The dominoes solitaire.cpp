#include <bits/stdc++.h>

using namespace std;

pair<int, int> l, r;
vector<pair<int, int>> ans, pieces;
bitset<15> used;
int n, m;

bool backtrack() {
    if (ans.size() == n) {
        if (ans.back().second == r.first) {
            return true;
        }
        return false;
    }
    for (int i = 0; i < m; i++) {
        int a = pieces[i].first, b = pieces[i].second;
        if (used[i]) continue;
        bool check = false;
        if (ans.empty()) {
            if (a == l.second) {
                ans.emplace_back(a, b);
                check = true;
            } else if (b == l.second) {
                ans.emplace_back(b, a);
                check = true;
            }
        } else {
            if (a == ans.back().second) {
                ans.emplace_back(a, b);
                check = true;
            } else if (b == ans.back().second) {
                ans.emplace_back(b, a);
                check = true;
            }
        }
        if (check) {
            used[i] = true;
            if (backtrack()) return true;
            ans.pop_back();
            used[i] = false;
        }
    }
    return false;
}

int main() {
    while (cin >> n, n) {
        cin >> m;
        pieces.resize(m);
        ans.clear();
        used.reset();
        cin >> l.first >> l.second >> r.first >> r.second;
        for (auto &i : pieces) {
            cin >> i.first >> i.second;
        }
        if (backtrack()) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}