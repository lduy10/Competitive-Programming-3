#include <bits/stdc++.h>

using namespace std;

int main() {
	double h, m;
	while (scanf("%lf:%lf", &h, &m) , (h || m)) {
		double a = abs(0.5 * (h * 60 + m) - m * 6);
		printf("%.3lf\n", min(360 - a, a));
	}
	return 0;
}
