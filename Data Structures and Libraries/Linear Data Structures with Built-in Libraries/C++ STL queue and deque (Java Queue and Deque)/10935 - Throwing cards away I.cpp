#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n, n) {
		deque <int> deck;
		vector <int> disCards;
		for (int i = 1; i <= n; i++) {
			deck.push_back(i);
		}
		while (deck.size() > 1) {
			int topCard = deck.front();
			disCards.push_back(topCard);
			deck.pop_front();
			int nextCard = deck.front();
			deck.pop_front();
			deck.push_back(nextCard);
		}
		cout << "Discarded cards:";
		for (int i = 0; i < disCards.size(); i++) {
			cout << " " << disCards[i];
			if (i < disCards.size() - 1) {
				cout << ",";
			}
		}
		cout << "\nRemaining card: " << deck.front() << "\n";
	}
	return 0;
}
