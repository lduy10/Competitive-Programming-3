#include <bits/stdc++.h>

using namespace std;

int main() {
    set<int> treeSet;
    for (int i = 1; i <= 20; i++) {
        treeSet.insert(i);
        treeSet.insert(i * 2);
        treeSet.insert(i * 3);
    }
    treeSet.insert(0);
    treeSet.insert(50);
    vector<int> points;
    for (auto i : treeSet) {
        points.emplace_back(i);
    }
    int s;
    while (cin >> s) {
        if (s <= 0) {
            cout << "END OF OUTPUT\n";
            return 0;
        }
        int combinations = 0, permutations = 0;
        if (s <= 180) {
            for (int i = 0; i < points.size(); i++) {
                for (int j = 0; j < points.size(); j++) {
                    for (int k = 0; k < points.size(); k++) {
                        if (points[i] + points[j] + points[k] == s) {
                            permutations++;
                            if (i >= j && j >= k) {
                                combinations++;
                            }
                        }
                    }
                }
            }
        }
        if (combinations > 0) {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << s << " IS " << combinations
                 << ".\nNUMBER OF PERMUTATIONS THAT SCORES " << s << " IS " << permutations << ".";
        } else {
            cout << "THE SCORE OF " << s << " CANNOT BE MADE WITH THREE DARTS.";
        }
        cout << "\n**********************************************************************\n";
    }
}