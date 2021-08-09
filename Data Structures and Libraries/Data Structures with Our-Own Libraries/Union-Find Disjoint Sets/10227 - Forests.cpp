#include <bits/stdc++.h>

using namespace std;

vector<int> p, rnk;
map<int, set<int>> m;
int ans;

vector<int> split(string &s) {
    s += ' ';
    vector<int> num;
    string tmp;
    for (char i : s) {
        if (i != ' ') {
            tmp += i;
        } else {
            int x;
            stringstream ss(tmp);
            ss >> x;
            num.emplace_back(x);
            tmp.clear();
        }
    }
    return num;
}

void init(int n) {
    m.clear();
    p.assign(n + 1, 0);
    rnk.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    ans = n;
}

int findSet(int i) {
    return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}

bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);
}

int check(int i, int j) {
    return m[i] == m[j];
}

void unionSet(int i, int j) {
    if (!isSameSet(i, j) && check(i, j)) {
        int x = findSet(i), y = findSet(j);
        if (rnk[x] > rnk[y]) {
            p[y] = p[x];
        } else {
            p[x] = p[y];
            if (rnk[x] == rnk[y]) {
                rnk[y]++;
            }
        }
        ans--;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int P, T;
        cin >> P >> T;
        init(P);
        cin.ignore();
        while (getline(cin, s)) {
            if (s.empty()) {
                break;
            }
            auto num = split(s);
            m[num[0]].insert(num[1]);
        }
        for (int i = 1; i <= P - 1; i++) {
            for (int j = i + 1; j <= P; j++) {
                unionSet(i, j);
            }
        }
        cout << ans << "\n";
        if (t) {
            cout << "\n";
        }
    }
    return 0;
}