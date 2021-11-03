#include <bits/stdc++.h>

#define int long long

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) + 16;
}

int32_t main() {
    /*ifstream fin("input.txt");
    ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t = 1;
    while (cin >> n, n) {
        vector<int> x(n), y(n), p(n), ans;
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }
        auto mn = DBL_MAX;
        do {
            double length = 0;
            for (int i = 0; i < n - 1; i++) {
                length += dist(x[p[i]], y[p[i]], x[p[i + 1]], y[p[i + 1]]);
            }
            if (length < mn) {
                mn = length;
                ans.assign(p.begin(), p.end());
            }
        } while (next_permutation(p.begin(), p.end()));
        printf("**********************************************************\n");
        printf("Network #%d\n", t++);
        for (int i = 0; i < n - 1; i++) {
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
                   x[ans[i]], y[ans[i]], x[ans[i + 1]], y[ans[i + 1]],
                   dist(x[ans[i]], y[ans[i]], x[ans[i + 1]], y[ans[i + 1]]));
        }

        printf("Number of feet of cable required is %.2lf.\n", mn);
    }
    /*fin.close();
    fout.close();*/
    return 0;
}