#include <bits/stdc++.h>

using namespace std;

vector<string> split(string &s) {
	vector<string> words;
	s += " ";
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ',' && s[i] != '.'
		        && s[i] != ':' && s[i] != ';'
		        && s[i] != '!' && s[i] != '?'
		        && s[i] != '"' && s[i] != '('
		        && s[i] != ')' && s[i] != ' ') {
			tmp += tolower(s[i]);
		} else {
			if (tmp.size()) {
				words.push_back(tmp);
			}
			tmp = "";
		}
	}
	return words;
}

int main() {
	string s;
	while (getline(cin, s), s != "****END_OF_INPUT****") {
		vector<string> T;
		if (s.size() > 0) {
			auto words = split(s);
			T.insert(T.end(), words.begin(), words.end());
		}
		while (getline(cin, s), s != "****END_OF_TEXT****") {
			if (s.size() > 0) {
				auto words = split(s);
				T.insert(T.end(), words.begin(), words.end());
			}
		}
		map<string, int> m;
		double lambda, n;
		vector<string> diffWords;
		for (auto e : T) {
			if (!m[e]) {
				diffWords.push_back(e);
			}
			m[e]++;
		}
		lambda = T.size();
		n = diffWords.size();
		double Emax = log10(lambda);
		double sum = 0;
		for (auto e : diffWords) {
			sum += m[e] * (Emax - log10(m[e]));
		}
		double ET = 1 / lambda * sum;
		double Erel = ET / Emax;
		printf("%d %.1f %d\n", (int)lambda, ET, (int)round(Erel * 100));
	}
	return 0;
}
