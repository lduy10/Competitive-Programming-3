#include <bits/stdc++.h>

using namespace std;

struct Member {
	string department;
	string title;
	string firstName;
	string lastName;
	string homeAddress;
	string homePhone;
	string workPhone;
	string campusBox;
};

bool comparator(Member &a, Member &b) {
	return a.lastName < b. lastName;
}

vector<string> split(string &s) {
	vector<string> infor;
	s += ',';
	string tmp = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ',') {
			tmp += s[i];
		} else {
			infor.push_back(tmp);
			tmp = "";
		}
	}
	return infor;
}

void showInfor(Member &m) {
	cout << "----------------------------------------\n";
	cout << m.title << " " << m.firstName << " " << m.lastName << "\n";
	cout << m.homeAddress << "\n";
	cout << "Department: " << m.department << "\n";
	cout << "Home Phone: " << m.homePhone << "\n";
	cout << "Work Phone: " << m.workPhone << "\n";
	cout << "Campus Box: " << m.campusBox << "\n";
}

int main() {
	int t;
	cin >> t;
	cin.ignore();
	vector<Member> members;
	while (t--) {
		string departmentName, memberInfor;
		getline(cin, departmentName);
		while (getline(cin, memberInfor), memberInfor.size() != 0) {
			auto infor = split(memberInfor);
			members.push_back({departmentName, infor[0], infor[1], infor[2],
			                   infor[3], infor[4], infor[5], infor[6]
			                  });
		}
	}
	sort(members.begin(), members.end(), comparator);
	for (Member e: members) {
		showInfor(e);
	}
	return 0;
}
