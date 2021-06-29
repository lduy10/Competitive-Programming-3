#include <bits/stdc++.h> 

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		string S;
		cin >> S;
		int n = S.size();
		if (S == "1" || S == "4" || S == "78") {
			cout << "+";
		} else if (S[n - 2] == '3' && S[n - 1] == '5') {
			cout << "-";
		} else if (S[0] == '9' && S[n - 1] == '4') {
			cout << "*";
		} else {
			cout << "?";
		}
		cout << "\n";
	}
	return 0;
}