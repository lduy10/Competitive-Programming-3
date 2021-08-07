#include <bits/stdc++.h>

using namespace std;

vector<int> p, r;
bitset<127> connected;

void init() {
    p.assign(127, 0);
    r.assign(127, 0);
    connected.reset();
    for (int i = 0; i < 127; i++) {
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
        if (r[x] > r[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (r[x] == r[y]) {
                r[y]++;
            }
        }
        connected[x] = true;
        connected[y] = true;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        string s;
        while (cin >> s, s[0] != '*') {
            unionSet(s[1] - 'A', s[3] - 'A');
        }
        cin >> s;
        vector<int> v;
        for (char i : s) {
            if (i != ',') {
                v.emplace_back(i - 'A');
            }
        }
        int trees = 0, acorns = 0;
        for (auto i : v) {
            if (findSet(i) == i) {
                if (connected[i]) {
                    trees++;
                } else {
                    acorns++;
                }
            }
        }
        cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
    }
    return 0;
}