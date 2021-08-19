#include <bits/stdc++.h>

using namespace std;

int main() {
    int sz, tc = 0;
    while (cin >> sz, sz) {
        vector<int> S(sz);
        for (int i = 0; i < sz; i++) {
            cin >> S[i];
        }
        sort(S.begin(), S.end());
        int sz = S.size();
        if (tc++) {
            cout << "\n";
        }
        for (int i = 0; i < sz - 5; i++) {
            for (int j = i + 1; j < sz - 4; j++) {
                for (int k = j + 1; k < sz - 3; k++) {
                    for (int l = k + 1; l < sz - 2; l++) {
                        for (int m = l + 1; m < sz - 1; m++) {
                            for (int n = m + 1; n < sz; n++) {
                                cout << S[i] << " " << S[j] << " " << S[k]
                                   << " " << S[l] << " " << S[m] << " " << S[n] << "\n";
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}