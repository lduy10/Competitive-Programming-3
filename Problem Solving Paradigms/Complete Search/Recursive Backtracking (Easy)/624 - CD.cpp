#include <bits/stdc++.h>

using namespace std;

vector<int> a, ans, tracks;
int n, m, mx;

void backtrack(int p, int sum) {
    if (sum > mx && sum <= n) {
        ans = tracks;
        mx = sum;
    }
    if (p == m || sum > n) {
        return;
    }
    tracks.emplace_back(a[p]);
    backtrack(p + 1, sum + a[p]);
    tracks.pop_back();
    backtrack(p + 1, sum);
}

int main() {
    while (cin >> n) {
        cin >> m;
        mx = 0;
        a.resize(m);
        ans.clear();
        tracks.clear();
        for (int &i : a) {
            cin >> i;
        }
        backtrack(0, 0);
        for (int &i : ans) {
            cout << i << " ";
        }
        cout << "sum:" << mx << "\n";
    }
    return 0;
}