#include <bits/stdc++.h>

using namespace std;

class FenwickTree{
private:
    vector<int> ft, arr;
    int n;

    int getSum(int p) {
        int sum = 0;
        p++;
        while (p > 0) {
            sum += ft[p];
            p -= p & (-p);
        }
        return sum;
    }

    void updateFT(int p, int diff) {
        p++;
        while (p <= n) {
            ft[p] += diff;
            p += p & (-p);
        }
    }

public:
    FenwickTree(const vector<int> &arr) {
        this->arr = arr;
        n = arr.size();
        ft.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            updateFT(i, arr[i]);
        }
    }

    int rsq(int qs, int qe) {
        return getSum(qe) - getSum(qs - 1);
    }

    void update(int p, int val) {
        int diff = val - arr[p];
        updateFT(p, diff);
        arr[p] = val;
    }
};

int main() {
    int n, tc = 0;
    while (cin >> n, n) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        FenwickTree ft(arr);
        string a;
        if (tc) {
            cout << "\n";
        }
        cout << "Case " << ++tc << ":\n";
        while (cin >> a, a != "END") {
            int x, y;
            cin >> x >> y;
            if (a == "S") {
                ft.update(x - 1, y);
            } else {
                cout << ft.rsq(x - 1, y - 1) << "\n";
            }
        }
    }
    return 0;
}
