#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
- 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 
두 나라가 공유하는 국경선을 오늘 하루 동안 연다

- 위의 조건에 의해 열어야 하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
- 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있다면, 그 나라를 오느 하루 동안은 연합이라고 한다.
- 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버림
- 연합을 해체하고 모든 국경선을 닫는다.

각 나라의 인구수가 주어졌을 때, 인구 이동이 며칠 동안 발생하는지 구하는 프로그램을 작성
*/

int N, L, R;
struct XY {
	int x;
	int y;
};
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<vector<XY>>& cont, vector<int>& moving, int r, int c) {
	deque<XY> dq;
	dq.push_back({ r, c });
	visited[r][c] = true;
	// 인구 이동이 발생하는 정점들을 가지는 변수
	vector<XY> location;
	
	int people = grid[r][c];
	while (!dq.empty()) {
		int x = dq.front().x, y = dq.front().y;
		dq.pop_front();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx >= N || nx < 0 || ny >= N || ny < 0) continue;
			if (visited[nx][ny] == true) continue;
			int acc = abs(grid[nx][ny] - grid[x][y]);
			if (acc >= L && acc <= R) {
				location.push_back({ nx, ny });
				dq.push_back({ nx, ny });
				visited[nx][ny] = true;
				people += grid[nx][ny];
			}
		}
	}
	if (location.empty()) return 0;
	location.push_back({ r, c });
	cont.push_back(location);
	int avg_people = people / location.size();
	moving.push_back(avg_people);
	return 1;
}

void moving_people(vector<vector<int>>& grid, vector<vector<XY>>& cont, vector<int> moving) {
	for (int i = 0; i < moving.size(); i++) {
		for (auto c : cont[i]) {
			grid[c.x][c.y] = moving[i];
		}
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	cin >> N >> L >> R;
	vector<vector<int>> grid(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	// bfs를 돌린다.
	// 인구 이동이 한번이라도 발생하면 return 1;
	// 인구 이동이 발생하지 않는다면 return 0; while문 종료
	
	int time = 0;
	while (true) {
		bool moved = false;
		vector<vector<bool>> visited(N, vector<bool>(N, 0));
		vector<vector<XY>> cont;
		vector<int> moving;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (moved == false) moved = bfs(grid, visited, cont, moving, i, j);
				else bfs(grid, visited, cont, moving, i, j);
			}
		}
		// 인구 이동이 한번에 발생해야 함
		moving_people(grid, cont, moving);
		//cout << time << "회" << "\n";
		//for (int i = 0; i < N; i++) {
		//	for (int j = 0; j < N; j++) {
		//		cout << grid[i][j] << " ";
		//	}
		//	cout << "\n";
		//}

		if (moved == false) break;
		time++;
	}
	cout << time << "\n";
	return 0;
}