#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int d;
        cin >> d;
        map<string, pair<int, int>> m;
        while (d--) {
            string name;
            int l, h;
            cin >> name >> l >> h;
            m[name] = {l, h};
        }
        int q;
        cin >> q;
        while (q--) {
            int p;
            cin >> p;
            vector<string> ans;
            for (const auto& i : m) {
                if (p >= i.second.first && p <= i.second.second) {
                    ans.emplace_back(i.first);
                }
            }
            if (ans.empty() || ans.size() > 1) {
                cout << "UNDETERMINED";
            } else {
                cout << ans[0];
            }
            cout << "\n";
        }
        if (t) {
            cout << "\n";
        }
    }
    return 0;
}