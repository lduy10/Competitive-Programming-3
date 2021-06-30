#include <bits/stdc++.h>

using namespace std;

int main() {
	int t, tc = 1;
	cin >> t;
	while (t--) {
		vector<pair<string, int>> arr(10);
		int max = 0;
		for (int i = 0; i < 10; i++) {
			cin >> arr[i].first >> arr[i].second;
			if (max < arr[i].second) {
				max = arr[i].second;
			}
		}
		printf("Case #%d:\n", tc);
		for (int i = 0; i < 10; i++) {
			if (arr[i].second == max) {
				cout << arr[i].first << "\n";
			}
		}
		tc++;
	}
	
	return 0;
}
