#include <bits/stdc++.h>

using namespace std;

class SegmentTree {
private:
    vector<int> st, arr, freq;
    unordered_map<int, pair<int, int>> pos;
    int n;

    static int left(int p) {
        return p << 1;
    }

    static int right(int p) {
        return (p << 1) + 1;
    }

    void build(int p, int ss, int se) {
        if (ss == se) {
            st[p] = freq[ss];
        } else {
            int mid = (ss + se) / 2;
            build(left(p), ss, mid);
            build(right(p), mid + 1, se);
            st[p] = max(st[left(p)], st[right(p)]);
        }
    }

    int rmo(int p, int ss, int se, int qs, int qe) {
        if (ss > qe || se < qs) {
            return -1;
        }
        if (qs <= ss && qe >= se) {
            return st[p];
        }
        int mid = (ss + se) / 2;
        return max(rmo(left(p), ss, mid, qs, qe), rmo(right(p), mid + 1, se, qs, qe));
    }

public:
    SegmentTree(const vector<int> &arr) {
        this->arr = arr;
        n = arr.size();
        unordered_map<int, int> cnt;
        int tmp = INT_MIN;
        for (int i = 0; i < n; i++) {
            cnt[arr[i]]++;
            if (cnt[arr[i]] == 1) {
                pos[tmp].second = i - 1;
                pos[arr[i]].first = i;
                tmp = arr[i];
            }
            if (i == n - 1) {
                pos[arr[i]].second = i;
            }
        }
        st.assign(4 * n, 0);
        freq.assign(n, 0);
        for (int i = 0; i < n; i++) {
            freq[i] = cnt[arr[i]];
        }
        build(1, 0, n - 1);
    }

    int maxOccurrence(int qs, int qe) {
        int ans;
        if (arr[qs] == arr[qe]) {
            return (qe - qs + 1);
        } else {
            int nl = pos[arr[qs]].second - qs + 1;
            qs = pos[arr[qs]].second + 1;
            int nr = qe - pos[arr[qe]].first + 1;
            qe = pos[arr[qe]].first - 1;
            ans = max({nl, nr, rmo(1, 0, n - 1, qs, qe)});
        }
        return ans;
    }
};

int main() {
    int n, q;
    while (cin >> n, n) {
        cin >> q;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        SegmentTree st(arr);
        while (q--) {
            int qs, qe;
            cin >> qs >> qe;
            cout << st.maxOccurrence(qs - 1, qe - 1) << "\n";
        }
    }
    return 0;
}