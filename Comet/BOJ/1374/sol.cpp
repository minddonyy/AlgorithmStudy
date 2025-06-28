#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Meeting {
	int start, end;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> num;

	vector<Meeting> meetings(num);
	for (int i = 0; i < num; i++) {
		int n;
		cin >> n >> meetings[i].start >> meetings[i].end;
	}

	sort(meetings.begin(), meetings.end(), [](const Meeting& a, const Meeting& b) {
		return a.start < b.start;
	});

	priority_queue<int, vector<int>, greater<int>> min_heap;
	min_heap.push(meetings[0].end);

	for (int i = 1; i < num; i++) {
		if (min_heap.top() <= meetings[i].start) {
			min_heap.pop();
		}
		min_heap.push(meetings[i].end);
	}

	cout << min_heap.size() << '\n';
	return 0;
}