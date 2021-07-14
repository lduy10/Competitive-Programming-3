#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		list<int> a, b;
		int m = n % 4 == 0 ? n / 4 : n / 4 + 1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (cnt < m) {
				a.push_back(i);
			} else {
				b.push_front(i);
			}
			if (i % 2 == 0) {
				cnt++;
			}
		}
		int d = a.size() - b.size();
		for (int i = 1; i <= d; i++) {
			b.push_front(0);
		}
		cnt = 1;
		int s = 0;
		string p = "front";
		cout << "Printing order for " << n << " pages:\n";
		for (auto i = a.begin(), j = b.begin(); i != a.end(); i++, j++) {
			if (*i % 2 == 0) {
				swap(*i, *j);
			}
			if (cnt % 2 == 0) {
				p = "back ";
			} else {
				p = "front";
				s++;
			}
			cnt++;
			cout << "Sheet " << s << ", " << p << ": ";
			if (*j != 0) {
				cout << *j;
			} else {
				cout << "Blank";
			}
			cout << ", ";
			if (*i != 0) {
				cout << *i;
			} else {
				cout << "Blank";
			}
			cout << "\n";
		}
		
		
	}
	
	
	
	return 0;
}
