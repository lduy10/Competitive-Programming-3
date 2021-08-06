#include <bits/stdc++.h>

using namespace std;

vector<string> split(string line) {
    line += " ";
    string tmp;
    vector<string> words;
    for (char i : line) {
        if (isalpha(i)) {
            tmp += tolower(i);
        } else if (!tmp.empty()) {
            words.emplace_back(tmp);
            tmp.clear();
        }
    }
    return words;
}

int main() {
    string line;
    set<string> s;
    while (getline(cin, line)) {
        if (!line.empty()) {
            auto words = split(line);
            for (const auto &i : words) {
                s.insert(i);
            }
        }
    }
    for (auto &i : s) {
        cout << i << "\n";
    }
    return 0;
}