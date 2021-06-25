#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	char key;
	int flag = 1;
	while ((key = getchar()) != EOF) {
		if (key == '"') {
			if (flag == 1) {
				printf("``");
			} else {
				printf("''");
			}
			flag = !flag;
		} else {
			putchar(key);
		}
	}
	return 0;
}