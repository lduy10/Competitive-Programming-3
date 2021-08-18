#include <bits/stdc++.h>

using namespace std;

void show(vector<string> &v) {
    for (const string& i : v) {
        cout << i << "\n";
    }
}

int main() {
    vector<string> hai = {"00", "01", "81"},
            bon = {"0000", "0001", "2025", "3025", "9801"},
            sau = {"000000", "000001", "088209", "494209", "998001"},
            tam = {"00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729",
                   "99980001"};
    int n;
    while (cin >> n) {
        if (n == 2) {
            show(hai);
        } else if (n == 4) {
            show(bon);
        } else if (n == 6) {
            show(sau);
        } else {
            show(tam);
        }
    }
    return 0;
}