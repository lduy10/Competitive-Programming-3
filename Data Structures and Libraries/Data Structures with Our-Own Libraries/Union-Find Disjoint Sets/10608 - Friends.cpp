#include <bits/stdc++.h>

using namespace std;

vector<int> p, rnk, cnt;
int ans;

void init(int n) {
    p.assign(n + 1, 0);
    rnk.assign(n + 1, 0);
    cnt.assign(n + 1, 1);
    ans = 1;
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
            if (ans < cnt[x]) {
                ans = cnt[x];
            }
        } else {
            p[x] = y;
            if (rnk[x] == rnk[y]) {
                rnk[y]++;
            }
            cnt[y] += cnt[x];
            if (ans < cnt[y]) {
                ans = cnt[y];
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        init(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            unionSet(a, b);
        }
        cout << ans << "\n";
    }
    return 0;
}