#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
직사각형 격자판
격자판의 행의 개수는 항상 2
열의 개수는 양수
각 칸은 검정(#) 혹은 하양(.)으로 칠해짐

격자에서 왼쪽 - 오른쪽 경로는 시작칸이 가장 왼쪽 열에 있는 칸
마지막 칸이 가장 오른쪽 열에 있는 경로

이때, 경로 상의 모든 칸은 하얀색이어야 하며, 경로상에서 연속하는 칸은 모두 인접해야 한다.


*/

int n;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
struct Node {
	int x, y, cnt;
};

int bfs(const vector<vector<char>>& v) {
	// [0][0], [1][0]에서 방문가능한지 확인하고 집어넣기
	queue<Node> q;
	vector<vector<bool>> visited(2, vector<bool>(n));
	for (int i = 0; i < 2; ++i)
		if (v[i][0] == '.') {
			q.push({ i, 0, 1 });
			visited[i][0] = true;
		}
	int cnt;
	while (!q.empty()) {
		Node cur = q.front(); q.pop();
		if (cur.y == n - 1) {
			cnt = cur.cnt;
			break;
		}
		for (int k = 0; k < 4; ++k) {
			int nx = cur.x + dx[k], ny = cur.y + dy[k];
			if (nx >= 2 || nx < 0 || ny >= n || ny < 0) continue;
			if (visited[nx][ny] || v[nx][ny] == '#') continue;
			q.push({ nx, ny, cur.cnt + 1 });
			visited[nx][ny] = true;
		}
	}
	return cnt;
}
void solve() {
	cin >> n;
	vector<vector<char>> v(2, vector<char>(n));
	int white = 0;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> v[i][j];
			if (v[i][j] == '.') ++white;
		}

	// [0][0] 혹은 [1][0]에서 시작할 수 있고,
	// 최단거리로 도착한 경로만
	cout << white - bfs(v) << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	solve();
	return 0;
}