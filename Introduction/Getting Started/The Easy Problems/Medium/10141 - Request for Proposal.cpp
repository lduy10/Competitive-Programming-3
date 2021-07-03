#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc = 1, t = 0;
	while (true) {
		string ans;
		int n, p;
		cin >> n >> p;
		if (n == 0 && p == 0) break;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			string r;
			getline(cin, r);
		}
		int minPrice = 999999999, maxR = -1; 
		for (int i = 0; i < p; i++) {
			string pName;
			getline(cin, pName);
			double d, nR;
			cin >> d >> nR;
			if (nR > maxR || nR == maxR && d < minPrice)  {
				ans = pName;
				minPrice = d;
				maxR = nR;
			} 
			cin.ignore();
			for (int j = 0; j < nR; j++) {
				string r;
				getline(cin, r);
			}
		}
		if (t > 0) cout << "\n";
		cout << "RFP #" << tc++ << "\n" << ans << "\n";
		t++;
	}
	return 0;
}
