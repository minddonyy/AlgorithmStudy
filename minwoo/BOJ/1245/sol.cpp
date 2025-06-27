#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M;
int dx[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int dy[8] = { 1, 0, -1, 0, 1, -1, 1, -1 };
struct XY { int x, y; };

bool bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int st_x, int st_y) {
	deque<XY> dq;
	dq.push_back({ st_x, st_y });
	vector<vector<bool>> vit(N, vector<bool>(M));
	vit[st_x][st_y] = true;
	while (!dq.empty()) {
		// 높이가 같은 위치들만 dq에 삽입, 만약 중간에 높이가 높은 곳을 만나면 return false
		XY cur = dq.front(); dq.pop_front();
		vector<XY> temp;
		for (int k = 0; k < 8; k++) {
			int nx = cur.x + dx[k], ny = cur.y + dy[k];
			if (nx >= N || nx < 0 || ny >= M || ny < 0 || vit[nx][ny] || grid[nx][ny] == 0) continue;
			if (grid[cur.x][cur.y] < grid[nx][ny]) return false;
			if (grid[cur.x][cur.y] == grid[nx][ny]) {
				temp.push_back({ nx, ny });
			}
			vit[nx][ny] = true;
		}
		for (const XY n : temp) {
			if (visited[n.x][n.y]) return false;
			dq.push_back({ n.x, n.y });
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	
	// 입력 및 배열 선언
	cin >> N >> M;
	vector<vector<int>> grid(N, vector<int>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> grid[i][j];
		}
	}

	// 높이가 0이 아닌 위치에서 산봉우리 조건을 확인
	// true면 ++
	int result = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (grid[i][j] == 0) continue;
			visited[i][j] = true;
			if (bfs(grid, visited, i, j)) result++;
		}
	}
	cout << result << "\n";
	return 0;
}