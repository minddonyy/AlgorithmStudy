using namespace std;
#include <iostream>
#include <algorithm>
const int MIN = -1000000000;
int row, col;
int arr[1000][1000];
int dp[1000][1000][3];
bool visited[1000][1000] = { 0 };
int dy[3] = { 0, 0, 1 };
int dx[3] = { -1, 1, 0 };

int dfs(int y, int x, int direc) {
	if (y == row - 1 && x == col - 1) {
		return arr[y][x];
	}
	if (dp[y][x][direc] != MIN) return dp[y][x][direc];
	int tempy, tempx, tempval;
	for (int i = 0; i < 3; ++i) {
		tempy = y + dy[i];
		tempx = x + dx[i];
		if (tempy < 0 || tempy >= row || tempx < 0 || tempx >= col || visited[tempy][tempx] == 1) continue;
		visited[tempy][tempx] = 1;
		int result = dfs(tempy, tempx, i);

		dp[y][x][direc] = max(dp[y][x][direc], result + arr[y][x]);
		visited[tempy][tempx] = 0;
	}
	return dp[y][x][direc];
}
int main()
{
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> arr[i][j];
			dp[i][j][0] = MIN;
			dp[i][j][1] = MIN;
			dp[i][j][2] = MIN;
		}
	}
	visited[0][0] = 1;
	
	cout << dfs(0, 0, 0) << endl;
	return 0;
}