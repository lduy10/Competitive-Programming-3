#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int q;
	while (scanf("%d", &q), q) {
		int x0, y0;
		scanf("%d %d", &x0, &y0);
		int x, y;
		while (q--) {
			scanf("%d %d", &x, &y);
			if (x == x0 || y == y0) {
				printf("divisa");
			} else if (x > x0) {
				if (y > y0) {
					printf("NE");
				} else {
					printf("SE");
				}
			} else {
				if (y < y0) {
					printf("SO");
				} else {
					printf("NO");
				}
			}
			printf("\n");
		}
	}
	return 0;
}