#include <bits/stdc++.h>

using namespace std;

vector <string> split(string s) {
    vector <string> res;
    s += " ";
    string tmp;
    for (char i : s) {
        if (i != ' ') {
            tmp += i;
        } else {
            res.push_back(tmp);
            tmp = "";
        }
    }
    return res;
}

int main() {
    map<string, string> m;
    string s;
    while (getline(cin, s), !s.empty()) {
        auto pair = split(s);
        m[pair[1]] = pair[0];
    }
    while (cin >> s) {
        if (m.find(s) != m.end()) {
            cout << m[s];
        } else {
            cout << "eh";
        }
        cout << "\n";
    }
    return 0;
}
