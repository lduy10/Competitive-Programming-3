#include <bits/stdc++.h>

#define int long long

using namespace std;

map<string, int> pos;

class Comparison {
public:
    bool operator()(string &a, string &b) {
        return pos[a] > pos[b];
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, tc = 1;
    while (cin >> n) {
        pos.clear();
        vector<string> beverages(n), ans;
        map<string, vector<string>> adj;
        map<string, int> inDegree;
        priority_queue<string, vector<string>, Comparison> listSources;
        for (int i = 0; i < n; i++) {
            cin >> beverages[i];
            pos[beverages[i]] = i;

        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            string a, b;
            cin >> a >> b;
            adj[a].emplace_back(b);
            inDegree[b]++;
        }
        for (string &i : beverages) {
            if (!inDegree[i]) {
                listSources.push(i);
            }
        }
        while (!listSources.empty()) {
            string u = listSources.top();
            listSources.pop();
            ans.emplace_back(u);
            for (string &i : adj[u]) {
                inDegree[i]--;
                if (!inDegree[i]) {
                    listSources.push(i);
                }
            }
        }
        cout << "Case #" << tc++ << ": Dilbert should drink beverages in this order:";
        for (string &i :ans) {
            cout << " " << i;
        }
        cout << ".\n\n";
    }
    return 0;
}