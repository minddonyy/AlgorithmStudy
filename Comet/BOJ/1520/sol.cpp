using namespace std;
#include <iostream>
#include <vector>
#include <queue>
int row, col, len;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int height[500][500] = { 0 };
int dp[500][500] = { 0 };
int visited[500][500] = { 0 };
//struct dataset
//{
//	int z, y, x;
//	bool operator < (const dataset& other) const {
//		return z < other.z;
//	}
//};
//dataset cur;
int dfs(int y, int x) {
	if (y == row - 1 && x == col - 1) return 1;
	if (visited[y][x]) return dp[y][x];

	int tempy, tempx, num = 0;
	for (int i = 0; i < 4; i++) {
		tempy = y + dy[i]; tempx = x + dx[i];
		if (tempy >= 0 && tempy < row && tempx >= 0 && tempx < col && height[tempy][tempx] < height[y][x]) {
			dp[tempy][tempx] += dp[y][x];
			num += dfs(tempy, tempx);
		}
	}
	dp[y][x] = num;
	visited[y][x] = 1;
	return num;
}
void solve() {
	// 이건 dfs + dp
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> height[i][j];
		}
	}
	
	/* 이건 우선순위 큐를 활용해서 하는방법.
	int tempy, tempx;
	vector<vector<int>> height(row, vector<int>(col, 0));
	vector<vector<int>> arr(row, vector<int>(col, 0));

	
	
	priority_queue<dataset> que;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> height[i][j];
			que.push({ height[i][j], i, j });
		}
	}
	arr[0][0] = 1;
	len = que.size();
	for (int i = 0; i < len; i++) {
		cur = que.top(); que.pop();
		for (int j = 0; j < 4; j++) {
			tempy = cur.y + dy[j]; tempx = cur.x + dx[j];
			if (tempy >= 0 && tempy < row && tempx >= 0 && tempx < col && height[tempy][tempx] < height[cur.y][cur.x]) {
				arr[tempy][tempx] += arr[cur.y][cur.x];
			}
		}
	}
	
	cout << arr[row - 1][col - 1] << '\n';
	*/
	cout << dfs(0, 0) << '\n';
}



int main() {
	solve();
	return 0;
}