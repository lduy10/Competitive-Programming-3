#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (cin >> n, n) {
        int maxSoFar = INT_MIN, maxEndingHere = 0;
        while (n--) {
            int x;
            cin >> x;
            maxEndingHere += x;
            maxSoFar = max(maxSoFar, maxEndingHere);
            maxEndingHere = max(maxEndingHere, (int) 0);
        }
        if (maxSoFar > 0) {
            cout << "The maximum winning streak is " << maxSoFar << ".";
        } else {
            cout << "Losing streak.";
        }
        cout << '\n';
    }
    return 0;
}