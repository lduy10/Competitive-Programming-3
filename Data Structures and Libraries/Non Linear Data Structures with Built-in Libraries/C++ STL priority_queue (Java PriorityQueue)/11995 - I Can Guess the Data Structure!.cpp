#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        bool isStack = true, isQueue = true, isPQ = true;
        while (n--) {
            int o, x;
            cin >> o >> x;
            if (o == 1) {
                s.emplace(x);
                q.emplace(x);
                pq.emplace(x);
            } else {
                if (s.empty()) {
                    isStack = false;
                    isQueue = false;
                    isPQ = false;
                } else {
                    auto z = s.top();
                    s.pop();
                    if (z != x) {
                        isStack = false;
                    }
                    z = q.front();
                    q.pop();
                    if (z != x) {
                        isQueue = false;
                    }
                    z = pq.top();
                    pq.pop();
                    if (z != x) {
                        isPQ = false;
                    }
                }
            }
        }
        if (isStack && !isQueue && !isPQ) {
            cout << "stack";
        } else if (!isStack && isQueue && !isPQ) {
            cout << "queue";
        } else if (!isStack && !isQueue && isPQ) {
            cout << "priority queue";
        } else if (!isStack && !isQueue) {
            cout << "impossible";
        } else {
            cout << "not sure";
        }
        cout << "\n";
    }
    return 0;
}