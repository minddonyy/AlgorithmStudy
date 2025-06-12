#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


int R, C, K;
int ans;
int dxy[4][2] = {
	{0, -1},
	{-1, 0},
	{0, 1},
	{1, 0}
};

void dfs(int depth, int x, int y, const vector<vector<char>>& arr, vector<vector<bool>>& visited) {
	if (x == 0 && y == C-1) {
		cout << "이동 거리 : " << depth << '\n';
		if (depth == K) ans++;
		return;
	}
	// 현재 시작점은 방문한 것으로 확인, 
	cout << "현재 정점 : " << x << ", " << y << '\n';
	for (int i = 0; i < 4; i++) {
		int dx = dxy[i][0], dy = dxy[i][1];
		int nx = x + dx, ny = y + dy;
		cout << nx << ", " << ny << '\n';
		
		if (nx >= R || nx < 0 || ny >= C || ny < 0) continue;
		if (arr[nx][ny] == 'T') continue;
		if (visited[nx][ny] == true) continue;

		visited[nx][ny] = true;
		dfs(depth + 1, nx, ny, arr, visited);
		visited[nx][ny] = false;
	}

}


int main() {
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> R >> C >> K;
	cin.ignore();

	vector<vector<char>> arr(R, vector<char>(C));
	vector<vector<bool>> visited(R, vector<bool>(C));

	string line;

	for (int i = 0; i < R; i++) {
		getline(cin, line);
		for (int j = 0; j < C; j++) {
			arr[i][j] = line[j];
		}
	}
	// 출력 확인
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	visited[R - 1][0] = true;
	dfs(1, R - 1, 0, arr, visited);
	cout << ans << '\n';
	return 0;
}