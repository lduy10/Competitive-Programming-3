#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<int> permutation;
vector<string> ans;

void backtrack(vector<int> &v, map<int, bool> &visited,
               map<pair<int, int>, bool> &constraints, int n) {
    if (permutation.size() == n) {
        string s;
        for (int &i : permutation) {
            s += (char) i;
        }
        ans.emplace_back(s);
        return;
    }
    for (int &i : v) {
        bool ok = true;
        for (auto &[key, val] : constraints) {
            int v1 = key.first, v2 = key.second;
            if (v2 == i && !visited[v1] || v1 == i && visited[v2]) {
                ok = false;
            }
        }
        if (ok) {
            if (!visited[i]) {
                permutation.emplace_back(i);
                visited[i] = true;
                backtrack(v, visited, constraints, n);
                visited[i] = false;
                permutation.pop_back();
            }
        }
    }
}

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int t = 0;
    while (getline(cin, s), !s.empty()) {
        ans.clear();
        vector<int> v;
        map<int, bool> visited;
        for (int i = 0; i < s.size(); i += 2) {
            v.emplace_back(s[i]);
            visited[s[i]] = false;
        }
        int n = v.size();
        getline(cin, s);
        map<pair<int, int>, bool> constraints;
        for (int i = 0; i < s.size() - 2; i += 4) {
            constraints[{s[i], s[i + 2]}] = true;
        }
        if (t++) {
            cout << "\n";
        }
        permutation.clear();
        for (auto &[key, val] : visited) {
            val = false;
        }
        backtrack(v, visited, constraints, n);
        sort(ans.begin(), ans.end());
        for (string &i : ans) {
            cout << i << "\n";
        }
    }
    return 0;
}