#include <bits/stdc++.h>

using namespace std;

vector<int> p, rnk;
int ans;

void init(int n) {
    p.assign(n + 1, 0);
    rnk.assign(n + 1, 0);
    ans = n;
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
        } else {
            p[x] = y;
            if (rnk[x] == rnk[y]) {
                rnk[y]++;
            }
        }
        ans--;
    }
}

int main() {
    int n, m, tc = 1;
    while (cin >> n >> m, n) {
        init(n);
        while (m--) {
            int i, j;
            cin >> i >> j;
            unionSet(i, j);
        }
        cout << "Case " << tc++ << ": " << ans << "\n";
    }
    return 0;
}