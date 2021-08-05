#include <bits/stdc++.h>

using namespace std;

bool comparator(pair<string, int> &a, pair<string, int> &b) {
    if (a.second != b.second) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    string s;
    while (true) {
        map<string, set<string>> sp;
        map<string, set<string>> m;
        vector<pair<string, int>> ans;
        string str;
        while (getline(cin, s), s[0] != '1') {
            if (s[0] == '0') {
                return 0;
            }
            if (isupper(s[0])) {
                str = s;
                set<string> newSet;
                m.insert({str, newSet});
            } else {
                sp[s].insert(str);
                m[str].insert(s);
            }
        }
        for (auto &i : sp) {
            if (i.second.size() > 1) {
                for (auto &j : m) {
                    auto k = find(j.second.begin(), j.second.end(), i.first);
                    if (k != j.second.end()) {
                        j.second.erase(k);
                    }
                }
            }
        }
        for (auto &i : m) {
            ans.emplace_back(i.first, i.second.size());
        }
        sort(ans.begin(), ans.end(), comparator);
        for (auto &i : ans) {
            cout << i.first << " " << i.second << "\n";
        }
    }
}
