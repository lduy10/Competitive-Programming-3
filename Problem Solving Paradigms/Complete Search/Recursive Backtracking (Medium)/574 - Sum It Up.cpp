#include <bits/stdc++.h>

using namespace std;

set<string, greater<string>> ans;
vector<int> a, b;
int t, n;

void backtrack(int p, int sum) {
    if (sum == t) {
        string s;
        for (int i = 0; i < b.size(); i++) {
            s += to_string(b[i]);
            if (i < b.size() - 1) {
                s += '+';
            }
        }
        ans.insert(s);
        return;
    }
    if (p == n || sum > t) {
        return;
    }
    b.emplace_back(a[p]);
    backtrack(p + 1, sum + a[p]);
    b.pop_back();
    backtrack(p + 1, sum);
}

int main() {
    while (cin >> t >> n, t) {
        ans.clear();
        a.resize(n);
        b.clear();
        for (int &i : a) {
            cin >> i;
        }
        backtrack(0, 0);
        cout << "Sums of " << t << ":\n";
        if (!ans.empty()) {
            for (auto &i : ans) {
                cout << i << "\n";
            }
        } else {
            cout << "NONE\n";
        }
    }
    return 0;
}