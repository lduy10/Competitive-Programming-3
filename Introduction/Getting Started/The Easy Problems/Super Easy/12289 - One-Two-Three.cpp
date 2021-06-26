#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string a;
		cin >> a;
		if (a.size() == 5) {
			cout << 3;
		} else if (a[0] == 'o' || a[1] == 'n') {
			cout << 1;
		} else {
			cout << 2;
		}
		cout << "\n";
	}
	return 0;
}