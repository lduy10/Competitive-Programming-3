#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int testCase = 1;
	string str;
	while (cin >> str) {
		if (str == "*") {
			break;
		}
		if (str == "Hajj") {
			str += "-e-Akbar";
		} else {
			str = "Hajj-e-Asghar";
		}
		printf("Case %d: ", testCase++);
		cout << str <<"\n";
	}
	return 0;
}