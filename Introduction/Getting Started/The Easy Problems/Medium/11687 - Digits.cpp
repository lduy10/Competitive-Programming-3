#include <bits/stdc++.h>

using namespace std;

int recurrence(int i, string n) {
	int nDigits = n.size();
	stringstream ss;
	ss << nDigits;
	if (ss.str() == n){
		return i;
	}
	return recurrence(i + 1, ss.str());
}

int main() {
	string n;
	while (cin >> n, n != "END") {
		cout << recurrence(1, n) << "\n";
	}
	return 0;
}

