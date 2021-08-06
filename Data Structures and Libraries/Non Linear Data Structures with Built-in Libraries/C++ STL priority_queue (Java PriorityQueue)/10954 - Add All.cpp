#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n, n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        while (n--) {
            int x;
            cin >> x;
            pq.emplace(x);
        }
        long long ans = 0;
        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += a + b;
            pq.emplace(a + b);
        }
        cout << ans << "\n";
    }
    return 0;
}