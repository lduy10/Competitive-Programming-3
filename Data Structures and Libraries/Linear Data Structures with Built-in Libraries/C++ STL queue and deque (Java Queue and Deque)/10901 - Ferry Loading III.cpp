#include <bits/stdc++.h>

using namespace std;

struct Car{
	int number;
	int time;
	string bank;
};

bool sortByTime(Car &a, Car &b) {
	return a.time < b.time;
}

bool sortByNumber(Car &a, Car &b) {
	return a.number < b.number;
}

int main() {
	int c;
	cin >> c;
	while (c--) {
		int n, t, m;
		cin >> n >> t >> m;
		string b = "left";
		vector<Car> cars(m);
		for (int i = 0; i < m; i++) {
			cars[i].number = i;
			cin >> cars[i].time >> cars[i].bank;
		}
		sort(cars.begin(), cars.end(), sortByTime);
		queue<Car> lb, rb;
		for (int i = 0; i < m; i++) {
			if (cars[i].bank == "left") {
				lb.push(cars[i]);
			} else {
				rb.push(cars[i]);
			}
		}
		vector<Car> ans;
		int time = cars[0].time;
		while (!lb.empty() || !rb.empty()) {
			int N = n;
			if (b == "left") {
				while (!lb.empty() && lb.front().time <= time && N) {
					lb.front().time = time + t;
					ans.push_back(lb.front());
					lb.pop();
					N--;
				}
				if (N < n) {
					time += t;
					b = "right";
				} else if (lb.empty() || !rb.empty() && lb.front().time > rb.front().time) {
					if (rb.front().time < time) {
						time += t;
					} else {
						time = rb.front().time + t;
					}
					b = "right";
				} else {
					time = lb.front().time;
				}
			} else {
				while (!rb.empty() && rb.front().time <= time && N) {
					rb.front().time = time + t;
					ans.push_back(rb.front());
					rb.pop();
					N--;
				}
				if (N < n) {
					time += t;
					b = "left";
				} else if (rb.empty() || !lb.empty() && rb.front().time > lb.front().time) {
					if (lb.front().time < time) {
						time += t;
					} else {
						time = lb.front().time + t;
					}
					b = "left";
				} else {
					time = rb.front().time;
				}
			}
		}
		sort(ans.begin(), ans.end(), sortByNumber);
		for (Car e : ans) {
			cout << e.time << "\n";
		}
		if (c) {
			cout << "\n";
		}
	}
	return 0;
}

