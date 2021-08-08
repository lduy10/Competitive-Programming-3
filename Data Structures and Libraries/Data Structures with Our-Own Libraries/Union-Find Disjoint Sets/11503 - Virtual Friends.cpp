#include <bits/stdc++.h>

using namespace std;

vector<int> p, rnk, cnt;

void init(int n) {
    p.assign(n + 1, 0);
    rnk.assign(n + 1, 0);
    cnt.assign(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
}

int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
        int x = findSet(i), y = findSet(j);
        if (rnk[x] > rnk[y]) {
            p[y] = x;
            cnt[x] += cnt[y];
            cout << cnt[x];
        } else {
            p[x] = y;
            if (rnk[x] == rnk[y]) {
                rnk[y]++;
            }
            cnt[y] += cnt[x];
            cout << cnt[y];
        }
    } else {
        int x = findSet(i);
        cout << cnt[x];
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        map<string, int> m;
        int f, x = 1;
        cin >> f;
        vector<pair<int, int>> v;
        while (f--) {
            string name1, name2;
            cin >> name1 >> name2;
            if (!m[name1]) {
                m[name1] = x++;
            }
            if (!m[name2]) {
                m[name2] = x++;
            }
            v.emplace_back(m[name1], m[name2]);
        }
        int n = m.size();
        init(n);
        for (auto &i : v) {
            unionSet(i.first, i.second);
        }
    }
    return 0;
}