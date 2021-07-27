#include <bits/stdc++.h>

using namespace std;

struct Team {
	string name;
	int points;
	int scoredGoals;
	int sufferedGoals;
	int playedMatches;
	int matchesEarnPoints;
};

bool comparator(Team &a, Team &b) {
	if (a.points != b.points) {
		return a.points > b.points;
	} else if (a.scoredGoals - a.sufferedGoals != b.scoredGoals - b.sufferedGoals) {
		return a.scoredGoals - a.sufferedGoals > b.scoredGoals - b.sufferedGoals;
	} else if (a.scoredGoals != b.scoredGoals) {
		return a.scoredGoals > b.scoredGoals;
	}
	string aName = "", bName = "";
	for (int i = 0; i < a.name.size(); i++) {
		aName += tolower(a.name[i]);
		bName += tolower(b.name[i]);
	}
	if (aName == bName) {
		return a.name > b.name;
	}
	return aName < bName;
}

int findPos(vector<Team> &tbl, string &name) {
	for (int i = 0; i < tbl.size(); i++) {
		if (tbl[i].name == name) {
			return i;
		}
	}
	return -1;
}

int main() {
	int t, g;
	bool notFirstCase = false;
	while (cin >> t >> g) {
		if (t == 0 && g == 0) {
			break;
		}
		if (notFirstCase) {
			cout << "\n";
		}
		notFirstCase = true;
		vector<Team> tbl;
		for (int i = 0; i < t; i++) {
			string name;
			cin >> name;
			tbl.push_back({name, 0, 0, 0, 0, 0});
		}
		for (int i = 0; i < g; i++) {
			string nameA, nameB, dash;
			int aGoals, bGoals;
			cin >> nameA >> aGoals >> dash >> bGoals >> nameB;
			int idxA = findPos(tbl, nameA), idxB = findPos(tbl, nameB);
			tbl[idxA].scoredGoals += aGoals;
			tbl[idxA].sufferedGoals +=  bGoals;
			tbl[idxB].scoredGoals += bGoals;
			tbl[idxB].sufferedGoals += aGoals;
			if (aGoals > bGoals) {
				tbl[idxA].points += 3;
				tbl[idxA].matchesEarnPoints++;
			} else if (aGoals < bGoals) {
				tbl[idxB].points += 3;
				tbl[idxB].matchesEarnPoints++;
			} else {
				tbl[idxA].points++;
				tbl[idxA].matchesEarnPoints++;
				tbl[idxB].points++;
				tbl[idxB].matchesEarnPoints++;
			}
			tbl[idxA].playedMatches++;
			tbl[idxB].playedMatches++;
		}
		sort(tbl.begin(), tbl.end(), comparator);
		for (int i = 0, r = 1; i < tbl.size(); i++, r++) {
			double p = (double) tbl[i].points / (3 * tbl[i].playedMatches) * 100;
			if (i == 0) {
				printf("%2d.", r);
			} else if (tbl[i].points != tbl[i - 1].points || tbl[i].scoredGoals != tbl[i - 1].scoredGoals || tbl[i].sufferedGoals != tbl[i - 1].sufferedGoals) {
				printf("%2d.", r);
			} else {
				printf("   ");
			}
			printf("%16s%4d%4d%4d%4d%4d", tbl[i].name.c_str(), tbl[i].points, tbl[i].playedMatches, tbl[i].scoredGoals, tbl[i].sufferedGoals, tbl[i].scoredGoals - tbl[i].sufferedGoals);
			if (isnan(p)) {
				printf("    N/A");
			} else {
				printf("%7.2f", p);
			}
			cout << "\n";
		}
	}
	return 0;
}
