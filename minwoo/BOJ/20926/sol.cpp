s#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
얼음 미로의 바닥은 빙판으로 되어 있어 발은 내디디면 바위에 부딪힐 때까지 미끄러진다.
얼음미로 바깥은 절벽이기 때문에 빠지면 탈출할 수 없다

얼음 미로에는 4가지 오브젝트가 있다
	1. 테라: 상하좌우 4방향을 이동할 수 있다. 얼음 미로에 단 1명의 테라만 존재, 테라가 최초 위치한 빙판의 미끌 시간은 0
	2. 바위; 통과할 수 없다. 미끄러지다 부딪히면 앞에서 멈춘다
	3. 구멍: 이곳에 빠지면 영영 탈출할 수 없다
	4. 출구: 이곳에 방문하는 즉시 얼음미로를 탈출한다. 얼음 미로에 단 1개의 출구만 존재한다.

미끄러지는 데 걸리는 시간을 미끌 시간이라고 하자. 각 빙판마다 미끌시간은 다를 수 있다.
어느 한쪽 방향으로 이동할 때, 테라가 미끄러지는 동안 위치한 빙판의 미끌시간을 더하면 이동 시간을 구할 수 있다.
단, 이동 시간 계산과 관련하여 두 가지 규칙이 있다.

- 어느 한쪽 방향으로 이동을 시작할 때, 시작 빙판의 미끌 시간은 포함하지 않는다.
- 테라가 출구로 들어갈 때, 출구 빙판의 미끌 시간은 포함하지 않는다.

# 한 방향으로 뻗어나갈 때, 절벽을 만날때까지 바위 혹은 출구가 아니거나 혹은 바위 앞에서 멈췄는데 미끌 시간의 합이 0인 경우 => 실패(break)
# 바위 앞에서 멈출 수 있고 미끌 시간의 합이 0이 아닐 경우 pq에 삽입
# 멈춘 장애물 앞이 "E" 인 경우 return acc + dist

*/
int INF = 1e9;

int W, H;
struct XY { 
	int x, y, dist;
	bool operator<(const XY& other) const {
		return dist > other.dist;
	}
};
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int dijkstra(vector<vector<char>>& grid, XY st, XY ed) {
	priority_queue<XY> pq;
	pq.push(st);
	vector<vector<int>> distance(H, vector<int>(W, INF));
	distance[st.x][st.y] = st.dist;
	XY cur;
	while (!pq.empty()) {
		cur = pq.top(); pq.pop();
		//cout << "시작 : " << cur.x << " " << cur.y << " " << cur.dist << "\n";
		if (cur.dist > distance[cur.x][cur.y]) continue;
		for (int i = 0; i < 4; i++) {
			int nx = cur.x, ny = cur.y, w = 0, acc;
			int di = dx[i], dj = dy[i];
			for (int j = 0; j < 500; j++) {
				nx += di;
				ny += dj;
				acc = cur.dist + w;
				// 해당 방향 탐색을 종료하는 경우
				// 1. 범위 밖을 벗어났을 경우(out of range)
				// 2. 바위를 만났는데 이동 거리가 0인 경우( == 'R' && acc == 0)
				// 3. 구멍을 만난 경우
				if (nx >= H || nx < 0 || ny >= W || ny < 0) break;
				if (grid[nx][ny] == 'H' || distance[nx][ny] <= acc) break;
				// 다익스트라 종료 조건: 탈출구를 만난 경우
				if (grid[nx][ny] == 'E') {
					distance[nx][ny] = acc;
					break;
				}

				// 현재 칸이 바위인 경우
				// 바위를 만나기 이전 칸을 삽입
				if (grid[nx][ny] == 'R') {
					nx -= di, ny -= dj;
					if (cur.x == nx && cur.y == ny) break;
					//cout << "삽입 : " << nx << ", " << ny << " / " << acc << "\n";
					pq.push({ nx, ny, acc });
					distance[nx][ny] = acc;
					break;
				}
				// 아직까지 종료조건이 아닌 경우, acc 에 현재 미끌시간을 합한다.
				int now = grid[nx][ny] - '0';
				if (now < 0 || now > 9) break;
				w += now;
			}
			//cout << "탐색 종료: " << w << " 방향:" << di << ", " << dj << "\n";
		}
	}
	if (distance[ed.x][ed.y] == INF) return -1;
	return distance[ed.x][ed.y];
}

int solve() {
	cin >> W >> H;
	vector<vector<char>> grid(H, vector<char>(W));
	string input;
	XY st = { 0, 0, 0 }, ed = { 0, 0, 0 };
	for (int i = 0; i < H; i++) {
		cin >> input;
		for (int j = 0; j < W; j++) {
			grid[i][j] = input[j];
			if (input[j] == 'T') {
				st = { i, j, 0 };
				grid[i][j] = '0';
			}
			else if (input[j] == 'E') ed = { i, j, 0 };
		}
	}
	//cout << st.x << " " << st.y << "\n";
	return dijkstra(grid, st, ed);
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	cout << solve() << "\n";

	return 0;
}