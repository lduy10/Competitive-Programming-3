#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		vector<int> bytes(100);
		string s;
		cin >> s;
		int p = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '+'){
				if (bytes[p] == 255) bytes[p] = 0;
				else bytes[p]++; 
			} 
			else if (s[i] == '-') {
				if (bytes[p] == 0) bytes[p] = 255;
				else bytes[p]--;
			}
			else if (s[i] == '>') {
				if (p == 99) p = 0;
				else p++;
			} 
			else if (s[i] == '<') {
				if (p == 0) p = 99;
				else p--;
			} 
		}
		printf("Case %d: ", tc);
		for (int i = 0; i < 100; i++) {
			if (i < 99) printf("%02X ", bytes[i]);
			else printf("%02X\n", bytes[i]);
		}
	}
	
	return 0;	
}
