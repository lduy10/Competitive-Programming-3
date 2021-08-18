#include <bits/stdc++.h>

using namespace std;

class SegmentTree{
private:
    vector<char> st;
    vector<int> arr;
    int n;

    static int left(int p) {
        return p << 1;
    }

    static int right(int p) {
        return (p << 1) + 1;
    }

    static char combine(char a, char b) {
        if (a == '0' || b == '0') return '0';
        if (a == b) return '+';
        return '-';
    }

    static char getSign(int val) {
        return (val > 0) ? '+' : (val == 0) ? '0' : '-';
    }

    void build(int p, int ss, int se) {
        if (ss == se) {
            st[p] = getSign(arr[ss]);
        } else {
            int mid = (ss + se) / 2;
            build(left(p), ss, mid);
            build(right(p), mid + 1, se);
            st[p] = combine(st[left(p)], st[right(p)]);
        }
    }

    void update(int p, int ss, int se, int index, int val) {
        if (index < ss || index > se) {
            return;
        }
        if (ss == se) {
            st[p] = getSign(val);
            return;
        }
        int mid = (ss + se) / 2;
        update(left(p), ss, mid, index, val);
        update(right(p), mid + 1, se, index, val);
        st[p] = combine(st[left(p)], st[right(p)]);
    }

    char getProduct(int p, int ss, int se, int qs, int qe) {
        if (qs > se || qe < ss) {
            return -1;
        }
        if (qs <= ss && qe >= se) {
            return st[p];
        }
        int mid = (ss + se) / 2;
        char leftChild = getProduct(left(p), ss, mid, qs, qe);
        char rightChild = getProduct(right(p), mid + 1, se, qs, qe);
        if(leftChild == -1) return rightChild;
        if(rightChild == -1) return leftChild;
        return combine(leftChild, rightChild);
    }

public:
    SegmentTree(const vector<int> &arr) {
        n = arr.size();
        this->arr = arr;
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    char getProduct(int qs, int qe) {
        return getProduct(1, 0, n - 1, qs, qe);
    }

    void update(int index, int val) {
        update(1, 0, n - 1, index, val);
    }
};

int main() {
    int n, k;
    while (cin >> n >> k) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        SegmentTree st(arr);
        while (k--) {
            char c;
            int a, b;
            cin >> c >> a >> b;
            if (c == 'C') {
                st.update(a - 1, b);
            } else {
                cout << st.getProduct(a - 1, b - 1);
            }
        }
        cout << "\n";
    }
    return 0;
}