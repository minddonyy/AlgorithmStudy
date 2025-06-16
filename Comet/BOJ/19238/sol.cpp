using namespace std;
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
int result = 0;
int length, num, fuel;
int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };
int y, x;
int tempy, tempx;

pair<int, int> find(vector<vector<int>>& arr) {
	if (arr[y][x] >= 2) {
		int temp = arr[y][x];
		arr[y][x] = 0;
		return make_pair(temp, 0);
	}
	queue<pair<int, int>> que;
	que.push(make_pair(y, x));
	int size, cnt = 0;
	pair<int, int> cur;
	vector< pair<int, int>> can;
	vector<vector<bool>> visited(length, vector<bool>(length, 0)); visited[y][x] = 1;
	int flag = 0;
	while (que.size() && flag == 0)
	{	
		
		cnt++;
		size = que.size();
		for (int i = 0; i < size; i++) {
			cur = que.front(); que.pop();
			for (int j = 0; j < 4; j++) {
				tempy = cur.first + dy[j]; tempx = cur.second + dx[j];
				if (tempy >= 0 && tempy < length && tempx >= 0 && tempx < length && !visited[tempy][tempx] && arr[tempy][tempx] != 1) {
					if (arr[tempy][tempx] >= 2) {
						can.push_back(make_pair(tempy, tempx));
						flag = 1;
					}
					que.push(make_pair(tempy, tempx)); visited[tempy][tempx] = 1;
				}
			}
		}
	}
	if (can.size()) {
		sort(can.begin(), can.end());
		int temp = arr[can[0].first][can[0].second];
		arr[can[0].first][can[0].second] = 0;
		y = can[0].first; x = can[0].second;
		
		return { temp, cnt };
	}
	else {
		return make_pair(-1, cnt);
	}
	
}
int move(vector<vector<int>>& arr, int tar_y, int tar_x) {
	if (y == tar_y && x == tar_x) {
		return 0;
	}
	queue<pair<int, int>> que;
	que.push(make_pair(y, x));
	int size, cnt = 0;
	pair<int, int> cur;
	vector<vector<bool>> visited(length, vector<bool>(length, 0)); visited[y][x] = 1;
	while (que.size())
	{
		cnt++;
		size = que.size();
		for (int i = 0; i < size; i++) {
			cur = que.front(); que.pop();
			for (int j = 0; j < 4; j++) {
				tempy = cur.first + dy[j]; tempx = cur.second + dx[j];
				if (tempy >= 0 && tempy < length && tempx >= 0 && tempx < length && !visited[tempy][tempx] && arr[tempy][tempx] != 1) {
					if (tempy == tar_y && tempx == tar_x) {
						y = tempy; x = tempx;
						return cnt;
					}
					que.push(make_pair(tempy, tempx)); visited[tempy][tempx] = 1;
				}
			}
		}
	}
	return -1;
}
void solve() {
	cin >> length >> num >> fuel;
	vector<vector<int>> arr(length, vector<int>(length));
	vector<vector<int>> locations(num + 2, vector<int>(4, 0));
	int distance; pair<int, int> target;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> y >> x; y--; x--;
	for (int i = 2; i < num + 2; i++) {
		cin >> locations[i][0] >> locations[i][1] >> locations[i][2] >> locations[i][3];
		locations[i][0]--; locations[i][1]--; locations[i][2]--; locations[i][3]--;
		arr[locations[i][0]][locations[i][1]] = i;
	}

	while (num)
	{
		target = find(arr);
		
		if (target.second > fuel || target.first == -1) {
			result = -1;
			return;
		}
		fuel -= target.second;
		distance = move(arr, locations[target.first][2], locations[target.first][3]);

		if (distance > fuel || distance == -1) {
			result = -1;
			return;
		}
		fuel += distance;
		num--;
	}
	result = fuel;
	return;
}

int main() {
	solve();
	cout << result << '\n';
	return 0;
}
