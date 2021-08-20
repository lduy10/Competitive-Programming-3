#include <bits/stdc++.h>

using namespace std;

int main() {
    int m;
    while (cin >> m) {
        vector<pair<int, int>> one, three;
        for (int i = 0; i < m; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++) {
                if (s[j] == '1') {
                    one.emplace_back(i, j);
                }
                if (s[j] == '3') {
                    three.emplace_back(i, j);
                }
            }
        }
        int ans = INT_MIN;
        for (auto &i : one) {
            int minDist = INT_MAX;
            for (auto &j : three) {
                int manhattanDistance = abs(i.first - j.first) + abs(i.second - j.second);
                if (manhattanDistance < minDist) {
                    minDist = manhattanDistance;
                }
            }
            if (ans < minDist) {
                ans = minDist;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}