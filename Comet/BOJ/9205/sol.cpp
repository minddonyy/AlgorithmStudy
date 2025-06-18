using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <string>
int num_store;
int input_x, input_y;
int length, cur;
int target;
string solve() {
	cin >> num_store;
	vector<vector<int>> arr(num_store + 2, vector<int>());
	vector<pair<int, int>> input(num_store + 2);
	queue<int> que;
	vector<bool> visited(num_store + 2);
	for (int i = 0; i < num_store + 2; i++) {
		cin >> input_y >> input_x; input[i] = make_pair(input_y, input_x);
	}
	for (int i = 0; i < num_store + 2; i++) {
		for (int j = i + 1; j < num_store + 2; j++) {
			length = abs(input[i].first - input[j].first) + abs(input[i].second - input[j].second);
			if ( length <= 1000) {
				arr[i].push_back(j);
				arr[j].push_back(i);
			}
		}
	}
	target = num_store + 1;
	que.push(0); visited[0] = 1;
	while (que.size())
	{
		cur = que.front(); que.pop();
		for (int i = 0; i < arr[cur].size(); i++) {
			if (arr[cur][i] == target) return "happy";
			if (!visited[arr[cur][i]]) {
				visited[arr[cur][i]] = 1;
				que.push(arr[cur][i]);
			}
		}
	}
	return "sad";
}



int main() {
	int T; cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cout << solve() << '\n';
	}
	return 0;
}