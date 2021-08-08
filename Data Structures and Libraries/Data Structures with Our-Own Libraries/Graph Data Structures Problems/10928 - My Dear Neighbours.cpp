#include <bits/stdc++.h>

using namespace std;

int split(string &s) {
    s += " ";
    int cnt = 0;
    for (char i : s) {
        if (i == ' ') {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        int p;
        cin >> p;
        cin.ignore();
        vector<int> places(p);
        int min = INT_MAX;
        for (int i = 0; i < p; i++) {
            string s;
            getline(cin, s);
            int x = split(s);
            if (x < min) {
                min = x;
            }
            places[i] = x;
        }
        vector<int> ans;
        for (int i = 0; i < p; i++) {
            if (places[i] == min) {
                ans.emplace_back(i + 1);
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
            if (i < ans.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}