using namespace std;
#include <iostream>
#include <vector>
#include <queue>

void solve() {
	priority_queue<long long, vector<long long>, greater<long long>> que;
	int num, merge;
	long long y, x, sum_num;
	cin >> num >> merge;
	for (int i = 0; i < num; i++) {
		cin >> y; que.push(y);
	}
	for (int i = 0; i < merge; i++) {
		y = que.top(); que.pop(); x = que.top(); que.pop();
		sum_num = y + x; que.push(sum_num); que.push(sum_num);
	}
	sum_num = 0;
	for (int i = 0; i < num; i++) {
		sum_num += que.top(); que.pop();
	}
	cout << sum_num << '\n';
}


int main() {
	solve();
	return 0;
}