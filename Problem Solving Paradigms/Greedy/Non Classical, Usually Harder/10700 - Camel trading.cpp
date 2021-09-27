#include <bits/stdc++.h>

#define int long long

using namespace std;

vector<string> split(string &s) {
    s += ' ';
    vector<string> res;
    string num;
    for (char &i : s) {
        if (isdigit(i)) {
            num += i;
        } else {
            string o;
            o += i;
            res.emplace_back(num);
            res.emplace_back(o);
            num.clear();
        }
    }
    return res;
}

void solve(vector<string> &a) {
    int mn = 0, mx = 1;
    vector<int> b;
    int p = 1;
    for (int i = 0; i < a.size(); i += 2) {
        if (a[i + 1] == "+") {
            p *= stoi(a[i]);
            b.emplace_back(p);
            p = 1;
        } else {
            p *= stoi(a[i]);
        }
    }
    b.emplace_back(p);
    for (int &i : b) {
        mn += i;
    }
    b.clear();
    p = 0;
    for (int i = 0; i < a.size(); i += 2) {
        if (a[i + 1] == "*") {
            p += stoi(a[i]);
            b.emplace_back(p);
            p = 0;
        } else {
            p += stoi(a[i]);
        }
    }
    b.emplace_back(p);
    for (int &i : b) {
        mx *= i;
    }
    cout << "The maximum and minimum are " << mx << " and " << mn << "." << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        vector<string> a = split(s);
        solve(a);
    }
    return 0;
}