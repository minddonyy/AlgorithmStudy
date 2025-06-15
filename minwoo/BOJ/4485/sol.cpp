#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int INF = 1e9;
int N;
const int MAX = 125;
int distances[MAX][MAX];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int dijkstra(const vector<vector<int>>& grid) {
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	memset(distances, 0x3f, sizeof(distances));
	int start_dist = grid[0][0];
	pq.push({ start_dist, 0, 0 });
	// 시작점 방문처리
	distances[0][0] = start_dist;
	
	while (!pq.empty()) {
		auto [dist, x, y] = pq.top(); pq.pop();
		if (dist > distances[x][y]) continue;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
			int acc = dist + grid[nx][ny];
			if (acc >= distances[nx][ny]) continue;
			pq.push({ acc, nx, ny });
			distances[nx][ny] = acc;
		}
	}

	return distances[N-1][N-1];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	vector<vector<int>> grid;
	int idx = 1;
	while (true) {
		cin >> N;
		if (N == 0) break;
		
		grid.assign(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> grid[i][j];
			}
		}
		cout << "Problem " << idx++ << ": " << dijkstra(grid) << "\n";
	}
	return 0;
}