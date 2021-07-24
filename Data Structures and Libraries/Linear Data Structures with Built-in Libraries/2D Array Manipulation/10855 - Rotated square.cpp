#include <bits/stdc++.h>

using namespace std;

bool d0(char S[500][500], char s[500][500], int n, int r, int c) {
	for (int i = r, k = 0; i < r + n; i++, k++) {
		for (int j = c, l = 0; j < c + n; j++, l++) {
			if (S[i][j] != s[k][l]) {
				return false;
			}
		}
	}
	return true;
}


bool d90(char S[500][500], char s[500][500], int n, int r, int c) {
	char rs[500][500];
	for (int i = 0, k = n - 1; i < n; i++, k--) {
		for (int j = 0; j < n; j++) {
			rs[j][k] = s[i][j];
		}
	}
	for (int i = r, k = 0; i < r + n; i++, k++) {
		for (int j = c, l = 0; j < c + n; j++, l++) {
			if (S[i][j] != rs[k][l]) {
				return false;
			}
		}
	}
	return true;
}

bool d180(char S[500][500], char s[500][500], int n, int r, int c) {
	char rs[500][500];
	for (int i = 0, k = n - 1; i < n; i++, k--) {
		for (int j = 0, l = n - 1; j < n; j++, l--) {
			rs[k][l] = s[i][j];
		}
	}
	
	for (int i = r, k = 0; i < r + n; i++, k++) {
		for (int j = c, l = 0; j < c + n; j++, l++) {
			if (S[i][j] != rs[k][l]) {
				return false;
			}
		}
	}
	return true;
}

bool d270(char S[500][500], char s[500][500], int n, int r, int c) {
	char rs[500][500];
	for (int i = 0; i < n; i++) {
		for (int j = 0, k = n - 1; j < n; j++, k--) {
			rs[k][i] = s[i][j];
		}
	}
	
	for (int i = r, k = 0; i < r + n; i++, k++) {
		for (int j = c, l = 0; j < c + n; j++, l++) {
			if (S[i][j] != rs[k][l]) {
				return false;
			}
		}
	}
	return true;
}


int main() {
	int N, n;
	while (cin >> N >> n, N, n) {
		char S[500][500], s[500][500];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> S[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> s[i][j];
			}
		}
		int cnt0 = 0, cnt90 = 0, cnt180 = 0, cnt270 = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (d0(S, s, n, i, j)) {
					cnt0++;
				} 
				if (d90(S, s, n, i, j)) {
					cnt90++;
				}
				if (d180(S, s, n, i, j)) {
					cnt180++;
				}
				if (d270(S, s, n, i, j)) {
					cnt270++;
				}
			}
		}
		cout << cnt0 << " " << cnt90 << " " << cnt180 << " " << cnt270 << "\n";
	}

	return 0;
}
