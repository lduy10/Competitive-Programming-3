#include <bits/stdc++.h>

using namespace std;

string s;

void backtrack(int p, const string& ans) {
    if (ans.size() == s.size()) {
        cout << ans << "\n";
        return;
    }
    for (int i = 0; i <= ans.size(); i++) {
        backtrack(p + 1, ans.substr(0, i) + s[p] + ans.substr(i));
    }
}

int main() {
    int tc = 0;
    while (cin >> s) {
        if (tc++) {
            cout << "\n";
        }
        backtrack(0, "");
    }
    return 0;
}