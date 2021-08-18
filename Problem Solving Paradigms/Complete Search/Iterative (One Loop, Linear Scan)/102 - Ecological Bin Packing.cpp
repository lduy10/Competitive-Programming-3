#include <bits/stdc++.h>

using namespace std;

string getString(vector<int> &v) {
    string s;
    for (auto i : v) {
        if (i == 0) {
            s += 'B';
        } else if (i == 1) {
            s += 'G';
        } else {
            s += 'C';
        }
    }
    return s;
}

int main() {
    vector<int> line(9);
    while (cin >> line[0] >> line[1] >> line[2]
               >> line[3] >> line[4] >> line[5]
               >> line[6] >> line[7] >> line[8]) {
        vector<int> bin1(3), bin2(3), bin3(3);
        for (int i = 0; i < 3; i++) {
            bin1[i] = line[i + 3] + line[i + 6];
            bin2[i] = line[i] + line[i + 6];
            bin3[i] = line[i] + line[i + 3];
        }
        vector<int> p = {0, 1, 2};
        vector<int> ans(p.begin(), p.end());
        while (next_permutation(p.begin(), p.end())) {
            int a = bin1[p[0]] + bin2[p[1]] + bin3[p[2]];
            int b = bin1[ans[0]] + bin2[ans[1]] + bin3[ans[2]];
            if (a < b) {
                ans.assign(p.begin(), p.end());
            }
            if (a == b && getString(p) < getString(ans)) {
                ans.assign(p.begin(), p.end());
            }
        }
        cout << getString(ans) << " " << bin1[ans[0]] + bin2[ans[1]] + bin3[ans[2]] << "\n";
    }
    return 0;
}