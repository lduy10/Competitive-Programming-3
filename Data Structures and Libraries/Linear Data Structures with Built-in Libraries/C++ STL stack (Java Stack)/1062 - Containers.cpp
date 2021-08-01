#include <bits/stdc++.h>

using namespace std;

int search(char &c, vector<stack<char>> &containers) {
	for (int i = 0; i < containers.size(); i++) {
		if (containers[i].top() >= c) {
			return i;
		}
	}
	return -1;
}

int main() {
	int tc = 1;
	string s;
	while (cin >> s, s != "end") {
		vector<stack<char>> containers;
		stack<char> newStack;
		newStack.push(s[0]);
		containers.push_back(newStack);
		for (int i = 1; i < s.size(); i++) {
			int p = search(s[i], containers);
			if (p != -1) {
				containers[p].push(s[i]);
			} else {
				stack<char> newStack;
				newStack.push(s[i]);
				containers.push_back(newStack);
			}
		}
		cout << "Case " << tc++ << ": " << containers.size() << "\n"; 
	}
	return 0;
}
