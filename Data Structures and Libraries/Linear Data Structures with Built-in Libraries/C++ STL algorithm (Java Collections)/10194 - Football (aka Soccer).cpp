#include <bits/stdc++.h>

using namespace std;

struct Team {
	string name;
	int points;
	int games;
	int wins;
	int ties;
	int losses;
	int goalDifference;
	int goalsScored;
	int goalsAgainst;
};

bool comparator(Team &a, Team &b) {
	if (a.points != b.points) {
		return a.points > b.points;
	} else if (a.wins != b.wins) {
		return a.wins > b.wins;
	} else if (a.goalDifference != b.goalDifference) {
		return a.goalDifference > b.goalDifference;
	} else if (a.goalsScored != b.goalsScored) {
		return a.goalsScored > b.goalsScored;
	} else if (a.games != b.games) {
		return a.games < b.games;
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

void split(string &game, string &nameA, string &nameB, int &goalsA, int &goalsB) {
	int i = 0;
	while (game[i] != '#') {
		nameA += game[i];
		i++;
	}
	i++;
	string ga = "", gb = "";
	while (game[i] != '@') {
		ga += game[i];
		i++;
	}
	i++;
	while (game[i] != '#') {
		gb += game[i];
		i++;
	}
	stringstream ss;
	ss << ga;
	ss >> goalsA;
	ss.clear();
	ss << gb;
	ss >> goalsB;
	i++;
	while (i < game.size()) {
		nameB += game[i];
		i++;
	}
}

int findPos(vector<Team> &teams, string &name) {
	for (int i = 0; i < teams.size(); i++) {
		if (teams[i].name == name) {
			return i;
		}
	}
}

int main() {
	int n;
	cin >> n;
	cin.ignore();
	while (n--) {
		string tournamentName;
		getline(cin, tournamentName);
		int t;
		cin >> t;
		cin.ignore();
		vector<Team> teams(t);
		for (int i = 0; i < t; i++) {
			getline(cin, teams[i].name);
		}
		int g;
		cin >> g;
		cin.ignore();
		for (int i = 0; i < g; i++) {
			string game, nameA = "", nameB = "";
			int goalsA, goalsB;
			getline(cin, game);
			split(game, nameA, nameB, goalsA, goalsB);
			int idxA = findPos(teams, nameA);
			int idxB = findPos(teams, nameB);
			teams[idxA].games++;
			teams[idxB].games++;
			teams[idxA].goalsAgainst += goalsB;
			teams[idxB].goalsAgainst += goalsA;
			teams[idxA].goalsScored += goalsA;
			teams[idxB].goalsScored += goalsB;
			teams[idxA].goalDifference = teams[idxA].goalsScored - teams[idxA].goalsAgainst;
			teams[idxB].goalDifference = teams[idxB].goalsScored - teams[idxB].goalsAgainst;
			if (goalsA > goalsB) {
				teams[idxA].points += 3;
				teams[idxA].wins++;
				teams[idxB].losses++;
			} else if (goalsA < goalsB) {
				teams[idxB].points += 3;
				teams[idxB].wins++;
				teams[idxA].losses++;
			} else {
				teams[idxA].points++;
				teams[idxB].points++;
				teams[idxA].ties++;
				teams[idxB].ties++;
			}
		}
		sort(teams.begin(), teams.end(), comparator);
		cout << tournamentName << "\n";
		for (int i = 0; i < t; i++) {
			printf ("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
			        i + 1,
			        teams[i].name.c_str(),
			        teams[i].points,
			        teams[i].games,
			        teams[i].wins, teams[i].ties,
			        teams[i].losses, teams[i].goalDifference,
			        teams[i].goalsScored,
			        teams[i].goalsAgainst);
		}
		if (n != 0) {
			cout << "\n";
		}
	}
	return 0;
}
