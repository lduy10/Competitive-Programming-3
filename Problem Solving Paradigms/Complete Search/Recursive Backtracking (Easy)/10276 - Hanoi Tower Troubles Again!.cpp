#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> pegs;
int n, ans;

bool square(int number) {
    int x = sqrt(number);
    return x * x == number;
}

void backtrack(int p) {
    if (ans < p) ans = p - 1;
    for (int i = 0; i < n; i++) {
        if (pegs[i].empty() || square(pegs[i].back() + p)) {
            pegs[i].emplace_back(p);
            backtrack(p + 1);
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ans = 0;
        cin >> n;
        pegs.assign(n, vector<int> (0));
        backtrack(1);
        cout << ans << "\n";
    }
    return 0;
}