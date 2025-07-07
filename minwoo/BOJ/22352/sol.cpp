#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
struct Node { int x, y; };

bool bfs(vector<vector<int>> v, const vector<vector<int>>& a, vector<vector<bool>> visited, Node st) {
	queue<Node> q;
	q.push(st);
	int nx, ny;
	// 시작할 때 색이랑 일치하는지 확인
	int c = v[st.x][st.y];
	int d = a[st.x][st.y];
	v[st.x][st.y] = a[st.x][st.y];
	while (!q.empty()) {
		Node cur = q.front(); q.pop();
		for (int k = 0; k < 4; k++) {
			nx = cur.x + dx[k], ny = cur.y + dy[k];
			if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
			if (visited[nx][ny] || v[nx][ny] != c) continue;
			v[nx][ny] = d;
			q.push({ nx,ny });
			visited[nx][ny] = true;
		}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (v[i][j] != a[i][j]) return false;

	return true;
}

void solve() {
	// 입력
	cin >> N >> M;
	vector<vector<int>> v(N, vector<int>(M));
	vector<vector<int>> a(N, vector<int>(M));
	vector<vector<bool>> visited(N, vector<bool>(M));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> v[i][j];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> a[i][j];
	int cnt = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (v[i][j] == a[i][j]) cnt++;
	if (cnt == (N*M)) {
		cout << "YES\n";
		return;
	}

	// 다른 부분을 확인하자
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (visited[i][j] || v[i][j] == a[i][j]) continue;
			visited[i][j] = true;
			bool res = bfs(v, a, visited, { i, j });
			if (res) {
				cout << "YES\n";
				return;
			}
		}
	
	cout << "NO\n";
	return;

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	solve();

	return 0;
}