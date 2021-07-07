#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		vector<list<int>> players(2);
		queue <int> table;
		int turn = 0;
		for (int i = 1; i <= 52; i++, turn = !turn) {
			string card;
			cin >> card;
			if (card[0] == '#') {
				return 0;
			}
			switch (card[1]) {
				case 'A':
					players[turn].push_front(4);
					break;
				case 'K':
					players[turn].push_front(3);
					break;
				case 'Q':
					players[turn].push_front(2);
					break;
				case 'J':
					players[turn].push_front(1);
					break;
				default:
					players[turn].push_front(0);
					break;
			}
		}
		bool cycle = false;
		while (!players[turn].empty()) {
			int currentCard = players[turn].front();
			players[turn].pop_front();
			table.push(currentCard);
			turn = !turn;
			while (currentCard) {
				if (players[turn].empty()) {
					cycle = false;
					break;
				} else {
					cycle = true;
				}
				int card = players[turn].front();
				players[turn].pop_front();
				table.push(card);
				if (card) {
					turn = !turn;
					currentCard = card;
				} else {
					currentCard--;
				}
			}
			if (cycle) {
				cycle = false;
				turn = !turn;
				while (!table.empty()) {
					players[turn].push_back(table.front());
					table.pop();
				}
			}
		}
		if (players[0].empty()) {
			cout << "1 " << setw(2) << players[1].size() << "\n";
		} else {
			cout << "2 " << setw(2) << players[0].size() << "\n";
		}
	}
	return 0;
}
