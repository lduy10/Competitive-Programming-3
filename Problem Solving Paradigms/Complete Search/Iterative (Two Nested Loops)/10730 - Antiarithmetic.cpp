#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &a, vector<int> &m) {
    int n = a.size();
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            int d = a[i] - a[j];
            int k = a[j] - d;
            if (m[k] > -1 && m[k] < 10000 && m[k] > m[a[j]]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string s;
    while (cin >> s) {
        stringstream ss(s);
        int n;
        ss >> n;
        if (!n) {
            return 0;
        }
        vector<int> m(10000, -1);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            m[a[i]] = i;
        }
        if (check(a, m)) {
            cout << "yes";
        } else {
            cout << "no";
        }
        cout << "\n";
    }
}