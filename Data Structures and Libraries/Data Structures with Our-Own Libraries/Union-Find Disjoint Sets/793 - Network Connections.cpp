#include <bits/stdc++.h>

using namespace std;

vector<int> p, rnk;
int sa, ua;

vector<string> split(string &s) {
    s += ' ';
    vector<string> f;
    string a(1, s[0]);
    f.emplace_back(a);
    string tmp;
    for (int i = 2; i < s.size(); i++) {
        if (s[i] != ' ') {
            tmp += s[i];
        } else {
            f.emplace_back(tmp);
            tmp.clear();
        }
    }
    return f;
}

void init(int n) {
   p.assign(n + 1, 0);
   rnk.assign(n + 1, 0);
   sa = 0;
   ua = 0;
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
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        init(n);
        cin.ignore();
        string s;
        while (getline(cin, s), !s.empty()) {
            auto f = split(s);
            int a, b;
            stringstream ss;
            ss << f[1];
            ss >> a;
            ss.clear();
            ss << f[2];
            ss >> b;
            if (f[0] == "c") {
                unionSet(a, b);
            } else {
                if (isSameSet(a, b)) {
                    sa++;
                } else {
                    ua++;
                }
            }
        }
        cout << sa << "," << ua << "\n";
        if (t) {
            cout << "\n";
        }
    }
    return 0;
}