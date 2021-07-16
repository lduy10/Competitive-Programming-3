#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 0) {
			break;
		}
		vector <string> d(n, "X");
		int index = 0;
		for (int i = 0; i < n; i++) {
			string c, s;
			cin >> c >> s;
			int w = s.size();
			while (true) {
				if (d[index] == "X") {
					w--;
				}
				if (w == 0) {
					break;
				}
				index++;
				if (index == n) {
					index = 0;
				}
			}
			d[index] = c;
		}
		for(int i = 0; i < n; i++) {
            if(i) {
            	cout << " ";
			}
            cout << d[i];
        }
        cout << "\n";
	}
	return 0;
}
