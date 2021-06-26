#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	string str;
	int testCase = 1;
	while (cin >> str) {
		if (str == "#") break;
		printf("Case %d: ", testCase);
		testCase++;
		if (str == "HELLO") {
			printf("ENGLISH");
		} else if (str == "HOLA") {
			printf("SPANISH");
		} else if (str == "HALLO") {
			printf("GERMAN");
		} else if (str == "BONJOUR") {
			printf("FRENCH");
		} else if (str == "CIAO") {
			printf("ITALIAN");
		} else if (str == "ZDRAVSTVUJTE"){
			printf("RUSSIAN");
		} else {
			printf("UNKNOWN");
		}
		printf("\n");
	}
	
	return 0;
}