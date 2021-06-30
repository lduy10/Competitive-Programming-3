#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 1;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int w0;
		cin >> w0;
		n--;
		int h = 0, l = 0;
		while (n--) {
			int w;
			cin >> w;
			if (w > w0) {
				h++;
			} else if (w < w0) {
				l++;
			}
			w0 = w;
		}
		printf("Case %d: %d %d\n", tc, h, l);
		tc++;
	}
	return 0;
}
