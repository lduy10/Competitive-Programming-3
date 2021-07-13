#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string &s) {
	int l = 0;
	int r = s.size() - 1;
	while (l < r) {
		if (s[l] != s[r]) {
			return false;
		}
		l++;
		r--;
	}
	return true;
}

bool isMirror(string &s) {
	int l = 0;
	int r = s.size() - 1;
	while (l <= r) {
		if (s[l] == 'A' && s[r] == 'A'
		        || s[l] == 'E' && s[r] == '3'
		        || s[l] == 'H' && s[r] == 'H'
		        || s[l] == 'I' && s[r] == 'I'
		        || s[l] == 'J' && s[r] == 'L'
		        || s[l] == 'L' && s[r] == 'J'
		        || s[l] == 'M' && s[r] == 'M'
		        || s[l] == 'O' && s[r] == 'O'
		        || s[l] == 'S' && s[r] == '2'
		        || s[l] == 'T' && s[r] == 'T'
		        || s[l] == 'U' && s[r] == 'U'
		        || s[l] == 'V' && s[r] == 'V'
		        || s[l] == 'W' && s[r] == 'W'
		        || s[l] == 'X' && s[r] == 'X'
		        || s[l] == 'Y' && s[r] == 'Y'
		        || s[l] == 'Z' && s[r] == '5'
		        || s[l] == '1' && s[r] == '1'
		        || s[l] == '2' && s[r] == 'S'
		        || s[l] == '3' && s[r] == 'E'
		        || s[l] == '5' && s[r] == 'Z'
		        || s[l] == '8' && s[r] == '8') {
			l++;
			r--;
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	string s;
	while (getline(cin, s)) {
		if (isPalindrome(s) && isMirror(s)) {
			cout << s << " -- is a mirrored palindrome.";
		} else if (isPalindrome(s)) {
			cout << s << " -- is a regular palindrome.";
		} else if (isMirror(s)) {
			cout << s << " -- is a mirrored string.";
		} else {
			cout << s << " -- is not a palindrome.";
		}
		cout << "\n\n";
	}
		return 0;
}
