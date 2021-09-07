#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> NOD(1000001, 0), seq(1000001, 0);
    for (int i = 1; i <= 1000000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            NOD[j]++;
        }
    }
    seq[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        seq[i] = seq[i - 1] + NOD[seq[i - 1]];
    }
    int t, tc = 1;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << "Case " << tc++ << ": " << distance(lower_bound(seq.begin(), seq.end(), a), upper_bound(seq.begin(), seq.end(), b)) << "\n";
    }
    return 0;
}