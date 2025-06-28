using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#include <cmath>
int length, low, high;
int arr[50][50] = { 0 };
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int visited[50][50] = { 0 };
int flag = 0, result = 0, tempy, tempx;
pair<int, int> cur;
bool moving(int y, int x) {
	
	vector<pair<int, int>> memo; memo.push_back(make_pair(y, x));
	queue<pair<int, int>> que; que.push(make_pair(y, x));
	visited[y][x] = 1;
	int sum_val = arr[y][x];
	while (!que.empty())
	{
		cur = que.front(); que.pop();
		for (int i = 0; i < 4; i++) {
			tempy = cur.first + dy[i]; tempx = cur.second + dx[i];
			if (tempy >= 0 && tempy < length &&  tempx >= 0 && tempx < length 
				&& !visited[tempy][tempx] 
				&& abs(arr[cur.first][cur.second] - arr[tempy][tempx]) >= low 
				&& abs(arr[cur.first][cur.second] - arr[tempy][tempx]) <= high) {
				visited[tempy][tempx] = 1;
				memo.push_back(make_pair(tempy, tempx));
				que.push(make_pair(tempy, tempx));
				sum_val += arr[tempy][tempx];
			}
		}
	}

	if (memo.size() > 1) {
		int change = sum_val / memo.size();
		for (int i = 0; i < memo.size(); i++) {
			arr[memo[i].first][memo[i].second] = change;
		}
		return 1;
	}
	else
	{	
		visited[y][x] = 0;
		return 0;
	}
	
}

void solve() {
	cin >> length >> low >> high;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cin >> arr[i][j];
		}
	}
	while (true)
	{
		// visited 초기화
		memset(visited, 0, sizeof(visited));

		// 국경선 열기 및 인구 이동
		flag = 0;
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length; j++) {
				if (!visited[i][j] && moving(i, j)) {
					flag = 1;
				}
			}
		}

		//  인구 이동이 존재했으면, 혹은 없었으면
		if (flag) {
			result++;
		}
		else
		{
			cout << result << '\n';
			return;
		}
	}

}



int main() {
	solve();
	return 0;
}