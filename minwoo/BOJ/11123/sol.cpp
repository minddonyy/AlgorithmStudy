#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T, H, W;
struct XY
{
	int x, y;
};
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void bfs(const vector<string>& grid, vector<vector<bool>>& visited, XY st) {
	queue<XY> dq;
	dq.push(st);
	visited[st.x][st.y] = true;
	XY cur;
	while (!dq.empty()) {
		cur = dq.front(); dq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if (nx >= H || nx < 0 || ny >= W || ny < 0 || visited[nx][ny] || grid[nx][ny] == '.') continue;
			dq.push({ nx, ny });
			visited[nx][ny] = true;
		}
	}
	return;
}

int solve() {
	cin >> H >> W;
	vector<string> grid(H);
	string input;
	for (int i = 0; i < H; i++) {
		cin >> input;
		grid[i] = input;
	}
	vector<vector<bool>> visited(H, vector<bool>(W));
	int res = 0;
	XY cur;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (grid[i][j] == '.' || visited[i][j]) continue;
			cur = { i, j };
			bfs(grid, visited, cur);
			res++;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cout << solve() << "\n";
	}

	return 0;
}