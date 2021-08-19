#include <bits/stdc++.h>

using namespace std;

int main() {
    int f, r;
    while (cin >> f, f) {
        cin >> r;
        vector<int> front(f), rear(r);
        vector<double> ratios;
        for (int i = 0; i < f; i++) {
            cin >> front[i];
        }
        for (int i = 0; i < r; i++) {
            cin >> rear[i];
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < f; j++) {
                ratios.emplace_back((double) rear[i] / front[j]);
            }
        }
        sort(ratios.begin(), ratios.end());
        double ans = -1;
        for (int i = 0; i < ratios.size() - 1; i++) {
            double d = ratios[i + 1] / ratios[i];
            if (ans < d) {
                ans = d;
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}