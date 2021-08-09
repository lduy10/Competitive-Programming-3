#include <bits/stdc++.h>

using namespace std;

vector<int> p, rnk, cnt;

void init(int n) {
    p.assign(n, 0);
    rnk.assign(n, 0);
    cnt.assign(n, 1);
    for (int i = 0; i < n; i++) {
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
        } else {
            p[x] = y;
            if (rnk[x] == rnk[y]) {
                rnk[y]++;
            }
            cnt[y] += cnt[x];
        }
    }
}

int main() {
    int n, m;
    while (cin >> n >> m, n) {
        init(n);
        while (m--) {
            int k;
            cin >> k;
            vector<int> g;
            for (int i = 0; i < k; i++) {
                int f;
                cin >> f;
                g.emplace_back(f);
            }
            if (k > 1) {
                for (int i = 0; i < k - 1; i++) {
                    unionSet(g[i], g[i + 1]);
                }
            }
        }
        cout << cnt[findSet(0)] << "\n";
    }
    return 0;
}