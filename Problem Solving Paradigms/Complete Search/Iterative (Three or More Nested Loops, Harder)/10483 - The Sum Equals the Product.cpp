#include <bits/stdc++.h>

using namespace std;

struct Triplet {
    double a;
    double b;
    double c;
};

bool comparator(const Triplet &t1, const Triplet &t2) {
    auto sum1 = t1.a + t1.b + t1.c, sum2 = t2.a + t2.b + t2.c;
    if (sum1 != sum2) return sum1 < sum2;
    return t1.a < t2.a;
}

int main() {
    vector<Triplet> v;
    for (int a = 1; a * 3 <= 25600; a++) {
        for (int b = a; b + b + a <= 25600; b++) {
            if (a * b <= 10000) continue;
            if (10000 * (a + b) % (a * b - 10000)) continue;
            int c = 10000 * (a + b) / (a * b - 10000);
            int sum = a + b + c;
            int product = a * b * c;
            if (sum > 25600 || c < b) continue;
            if (sum == product / 10000) {
                v.push_back({(double) a / 100, (double) b / 100, (double) c / 100});
            }
        }
    }
    sort(v.begin(), v.end(), comparator);
    double l, h;
    while (cin >> l >> h) {
        for (auto &e : v) {
            auto sum = e.a + e.b + e.c;
            if (sum >= l && sum <= h) {
                printf("%.2f = %.2f + %.2f + %.2f = %.2f * %.2f * %.2f\n",
                       sum, e.a, e.b, e.c, e.a, e.b, e.c);
            }
        }
    }
    return 0;
}