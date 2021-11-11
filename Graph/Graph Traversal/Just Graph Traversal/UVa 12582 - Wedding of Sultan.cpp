#include <bits/stdc++.h>

#define int long long

using namespace std;

int32_t main() {
    /* ifstream fin("input.txt");
     ofstream fout("output.txt");*/
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, tc = 1;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        stack<char> myStack;
        myStack.push(s[0]);
        map<char, int> m;
        for (int i = 1; i < s.size(); i++) {
            char top = myStack.top();
            if (s[i] == top) {
                myStack.pop();
            } else {
                m[top]++;
                m[s[i]]++;
                myStack.push(s[i]);
            }
        }
        cout << "Case " << tc++ << "\n";
        for (auto &[key, value] : m) {
            cout << key << " = " << value << "\n";
        }
    }
    return 0;
}
