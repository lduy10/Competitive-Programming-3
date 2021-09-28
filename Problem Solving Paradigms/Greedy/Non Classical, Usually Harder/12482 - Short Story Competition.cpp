#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, c;
    while (cin >> n >> l >> c) {
        int pages = 1, line = 0, characters = 0;
        while (n--) {
            string word;
            cin >> word;
            int sz = word.size();
            if (characters + sz > c) {
                line++;
                if (line == l) {
                    line = 0;
                    pages++;
                }
                characters = sz + 1;
            } else {
                characters += sz + 1;
            }
        }
        cout << pages << "\n";
    }
    return 0;
}