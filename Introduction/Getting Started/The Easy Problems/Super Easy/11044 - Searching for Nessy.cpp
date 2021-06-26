#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		n = n / 3;
		m = m / 3;
		printf("%d\n", n * m);
	}
	return 0;
}