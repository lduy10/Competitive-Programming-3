#include <bits/stdc++.h>

#define int long long

using namespace std;

double func(int t, double irr, const vector<double> &cf) {
    double res = cf[0];
    for (int i = 1; i <= t; i++) {
        res += cf[i] / pow((1 + irr), i);
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    while (cin >> t, t) {
        vector<double> cf(t + 1);
        for (auto &i : cf) {
            cin >> i;
        }
        double a = -1, b = 128;
        while (b - a >= 1e-9) {
            double c = (a + b) / 2;
            if (func(t, c, cf) < 0) {
                b = c;
            } else {
                a = c;
            }
        }
        cout << setprecision(2) << fixed << (a + b) / 2 << "\n";
    }
    return 0;
}