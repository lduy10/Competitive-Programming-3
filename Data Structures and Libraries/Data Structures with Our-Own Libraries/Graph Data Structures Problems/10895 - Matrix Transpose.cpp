#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<vector<pair<int, int>>> matrix(n);
        for (int i = 0; i < m; i++) {
            int r;
            cin >> r;
            vector<int> p(r);
            for (int j = 0; j < r; j++) {
                cin >> p[j];
            }
            for (int j = 0; j < r; j++) {
                int e;
                cin >> e;
                matrix[p[j] - 1].emplace_back(e, i);
            }
        }
        cout << n << " " << m << "\n";
        for (auto &i : matrix) {
            cout << i.size();
            for (auto &j : i) {
                cout << " " << j.second + 1;
            }
            cout << "\n";
            for (int j = 0; j < i.size(); j++) {
                cout << i[j].first;
                if (j < i.size() - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
    }
    return 0;
}