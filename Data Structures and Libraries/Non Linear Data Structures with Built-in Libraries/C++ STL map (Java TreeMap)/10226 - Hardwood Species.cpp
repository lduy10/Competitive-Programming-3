#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    cin.ignore();
    while (t--) {
        string s;
        map<string, int> m;
        int cnt = 0;
        while (getline(cin, s), !s.empty()) {
            m[s]++;
            cnt++;
        }
        for (auto &i : m) {
            printf("%s %.4f\n", i.first.c_str(), (double) i.second * 100 / cnt);
        }
        if (t) {
            cout << "\n";
        }
    }
}
