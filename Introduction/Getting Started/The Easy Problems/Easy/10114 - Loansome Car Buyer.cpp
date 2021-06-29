#include <bits/stdc++.h>

using namespace std;

int main() {
	int months, nDep;
	double loan, dPay, dPercent[101];
	while (true) {
		cin >> months >> dPay >> loan >> nDep;
		if (months < 0) {
			break;
		}
		for (int i = 0; i < nDep; i++) {
			int m;
			double p;
			cin >> m >> p;
			for (int i = m; i < 101; i++) {
				dPercent[i] = p;
			}
		}
		int now = 0;
		double monthlyPayment = loan / months;
		double value = (loan + dPay) * (1 - dPercent[0]);
		while (value < loan) {
			now++;
			loan -= monthlyPayment;
			value = value * (1 - dPercent[now]);
		}
		cout << now << " month";
		if (now != 1) {
			cout << 's';
		}
		cout << "\n";
	}
	return 0;
}