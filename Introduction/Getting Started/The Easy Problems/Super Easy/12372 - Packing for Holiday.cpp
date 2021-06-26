#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t, testCase = 1;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		printf("Case %d: ", testCase++);
		if (a > 20 || b > 20 || c > 20) {
			cout << "bad";
		} else {
			cout << "good";
		}
		cout << "\n";
	}
	return 0;
}