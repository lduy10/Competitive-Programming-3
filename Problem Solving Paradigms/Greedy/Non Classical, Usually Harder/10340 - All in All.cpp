#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    while (cin >> a >> b) {
        int p1 = 0, p2 = 0;
        while (p1 < a.size() && p2 < b.size()) {
            if (a[p1] != b[p2]) {
                p2++;
            } else {
                p1++;
                p2++;
            }
        }
        p1 == a.size() ? cout << "Yes" : cout << "No";
        cout << "\n";
    }
    return 0;
}