#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int min = 100, max = -1;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if (x < min) min = x;
			if (x > max) max = x;
		}	
		printf("%d\n", (max - min) * 2);
	}
	return 0;
}