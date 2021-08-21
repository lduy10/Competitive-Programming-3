#include <bits/stdc++.h>

using namespace std;

struct Quartet {
    double a, b, c, d;
};

bool comparator(const Quartet &q1, const Quartet &q2) {
    if (q1.a != q2.a) return q1.a < q2.a;
    if (q1.b != q2.b) return q1.b < q2.b;
    if (q1.c != q2.c) return q1.c < q2.c;
    return q1.d < q2.d;
}

int main() {
    vector<Quartet> v;
    for (int a = 1; a * 4 <= 2000; a++) {
        for (int b = a; a + b * 3 <= 2000; b++) {
            for (int c = b; a + b + c * 2 <= 2000; c++) {
                if (a * b * c <= 1000000 || 1000000 * (a + b + c) % (a * b * c - 1000000)) continue;
                int d = 1000000 * (a + b + c) / (a * b * c - 1000000);
                if (d < c) continue;
                int sum = a + b + c + d, product = a * b * c * d;
                if (sum > 2000 || sum != product / 1000000) continue;
                v.push_back({(double) a / 100, (double) b / 100, (double) c / 100, (double) d / 100});
            }
        }
    }
    sort(v.begin(), v.end(), comparator);
    for (auto &i : v) {
        printf("%.2f %.2f %.2f %.2f\n", i.a, i.b, i.c, i.d);
    }
    return 0;
}