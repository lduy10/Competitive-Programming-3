#include <bits/stdc++.h>

#define int long long

using namespace std;

double p, q, r, s, t, u;

double func(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> p >> q >> r >> s >> t >> u) {
        double l = 0, h = 1;
        double mid = l;
        while (h - l >= 1e-9) {
            mid = (l + h) / 2;
            if (func(mid) < 0) {
                h = mid;
            } else {
                l = mid;
            }
        }
        if (fabs(func(mid)) <= 1e-4) {
            cout << setprecision(4) << fixed << mid;
        } else {
            cout << "No solution";
        }
        cout << "\n";
    }
    return 0;
}