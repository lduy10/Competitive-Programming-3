#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int n, testCase = 1;
	while (cin >> n, n) {
		int ans = 0;
		while (n--) {	
			int x;
			cin >> x;
			if (x > 0) {
				ans++;
			} else {
				ans--;
			}
		}
		printf("Case %d: %d\n", testCase, ans);
		testCase++;
	}
	return 0;
}