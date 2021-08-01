#include <bits/stdc++.h>

using namespace std;

int main() {
	while (true) {
		vector<stack<string>> piles(52);
		for (int i = 0; i < 52; i++) {
			string card;
			cin >> card;
			if (card == "#") {
				return 0;
			}
			piles[i].push(card);
		}
		for (int i = 1; i < piles.size(); i++) {
			if (i - 3 >= 0 && (piles[i].top()[0] == piles[i - 3].top()[0]
			                   || piles[i].top()[1] == piles[i - 3].top()[1])) {
				piles[i - 3].push(piles[i].top());
				piles[i].pop();
				if (piles[i].empty()) {
					piles.erase(piles.begin() + i, piles.begin() + i + 1);
				}
				i -= 4;
			} else if (i - 1 >= 0 && (piles[i].top()[0] == piles[i - 1].top()[0]
			                          || piles[i].top()[1] == piles[i - 1].top()[1])) {
				piles[i - 1].push(piles[i].top());
				piles[i].pop();
				if (piles[i].empty()) {
					piles.erase(piles.begin() + i, piles.begin() + i + 1);
				}
				i -= 2;
			}
		}
		int n = piles.size();
		cout << n << " pile";
		if (n > 1) {
			cout << "s";
		}
		cout << " remaining:";
		for (auto e : piles) {
			cout << " " << e.size();
		}
		cout << "\n";
	}
	return 0;
}
