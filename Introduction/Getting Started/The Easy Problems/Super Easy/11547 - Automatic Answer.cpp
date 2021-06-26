#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		n = (n * 567 / 9 + 7492) * 235 / 47 - 498;
		if (n < 0) {
			n *= -1;
		}
		printf("%d\n", n / 10 % 10);
	}
	return 0;
}