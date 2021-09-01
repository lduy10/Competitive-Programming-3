#include <bits/stdc++.h>

using namespace std;

vector<int> marbles;
int n, q;

int main() {
    int tc = 1;
    while (cin >> n >> q, n) {
        marbles.resize(n);
        for (int &i : marbles) {
            cin >> i;
        }
        sort(marbles.begin(), marbles.end());
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            if (!m[marbles[i]]) {
                m[marbles[i]] = i + 1;
            }
        }
        cout << "CASE# " << tc++ << ":\n";
        while (q--) {
            int number;
            cin >> number;
            int index = m[number];
            cout << number << " ";
            if (index) {
                cout << "found at " << index;
            } else {
                cout << "not found";
            }
            cout << "\n";
        }
    }
    return 0;
}