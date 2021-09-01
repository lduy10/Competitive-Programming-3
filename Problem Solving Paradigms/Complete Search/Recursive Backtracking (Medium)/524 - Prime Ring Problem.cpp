#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
vector<bool> used;
int n;

bool prime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void backtrack(int p) {
    if (p == n + 1) {
        if (prime(ans[0] + ans.back())) {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i];
                if (i < ans.size() - 1) {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (!used[i] && prime(ans.back() + i)) {
            used[i] = true;
            ans.emplace_back(i);
            backtrack(p + 1);
            used[i] = false;
            ans.pop_back();
        }
    }
}

int main() {
    int tc = 0;
    while (cin >> n) {
        if (tc) cout << "\n";
        cout << "Case " << ++tc << ":\n";
        ans.assign(1, 1);
        used.assign(n + 1, false);
        backtrack(2);
    }
    return 0;
}