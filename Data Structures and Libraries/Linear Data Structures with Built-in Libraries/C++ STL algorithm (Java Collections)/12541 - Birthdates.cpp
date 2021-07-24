#include <bits/stdc++.h>

using namespace std;

struct Student{
	string name;
	int d;
	int m;
	int y;
};

bool comparator(Student &a, Student &b) {
	if (a.y != b.y) {
		return a.y < b.y;
	} else if (a.m != b.m) {
		return a.m < b.m;
	} else {
		return a.d < b.d;
	}
}

int main() {
	int n;
	cin >> n;
	vector<Student> co_lat(n);
	for (int i = 0; i < n; i++) {
		cin >> co_lat[i].name >> co_lat[i].d >> co_lat[i].m >> co_lat[i].y;
	}
	sort(co_lat.begin(), co_lat.end(), comparator);
	cout << co_lat[n - 1].name << "\n" << co_lat[0].name << "\n";
	return 0;
}
