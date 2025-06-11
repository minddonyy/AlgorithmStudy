#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
using namespace std;

int n, w, L;
string line;
deque<int> q;


int main() {
	cin >> n >> w >> L;
	cin.ignore();
	getline(cin, line);
	istringstream iss(line);

	for (int i = 0; i < w; i++) q.push_back(0);
	vector<int> trucks;
	int num;
	while (iss >> num) {
		trucks.push_back(num);
	}

	int weight = 0, time = 0;
	int idx = 0, now;
	while (idx < n) {
		weight -= q[0];
		q.pop_front();
		now = trucks[idx];
		if (weight + now <= L) {
			q.push_back(now);
			weight += now;
			idx++;
		}
		else {
			q.push_back(0);
		}
		time++;
	}
	while (q.size()) {
		q.pop_front();
		time++;
	}
	cout << time << "\n";
	return 0;
}