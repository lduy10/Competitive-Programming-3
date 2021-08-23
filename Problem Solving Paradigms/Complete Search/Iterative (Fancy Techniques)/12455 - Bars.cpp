#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> bars(p);
        for (int &i : bars) {
            cin >> i;
        }
        bool possible = false;
        if (n == 0) possible = true;
        for (int i = 0; i < (1 << p) && !possible; i++) {
            int sum = 0;
            for (int j = 0; j < p; j++) {
                if (i & (1 << j)) {
                    sum += bars[j];
                    if (sum == n) {
                        possible = true;
                        break;
                    }
                }
            }
        }
        possible ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}