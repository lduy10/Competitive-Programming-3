#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t, testCase = 1;
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		printf("Case %d: ", testCase);
		testCase++;
		if ((a > b && c < b) || (a < b && c > b)) {
			printf("%d", b);
		} else if ((b > a && c < a) || (b < a && c > a)) {
			printf("%d", a);
		} else {
			printf("%d", c);
		}
		printf("\n");
	}
	return 0;
}