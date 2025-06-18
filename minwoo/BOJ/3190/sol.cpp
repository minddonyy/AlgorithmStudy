#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

int N, K, L;
// 0: (-1, 0), 1: (0, 1), 2: (1, 0), 3: (0, -1)
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int angle = 90;
// 0: 상, 1: 좌, 2: 하, 3: 우
unordered_map<string, int> DIRECTION = {
	{"D", 90},
	{"L", -90}
};

struct Cell {
	int num;
	string ch;
};

struct XY {
	int x;
	int y;
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	// 배열 생성
	cin >> N;
	vector<vector<int>> grid(N, vector<int>(N, 0));

	// 사과 좌표 확인 및 위치
	cin >> K;
	int ax, ay;
	for (int k = 0; k < K; k++) {
		cin >> ax >> ay;
		grid[ax - 1][ay - 1] = 1;
	}

	// 방향 변환 정보(x초가 끝난 뒤에)
	cin >> L;
	vector<Cell> command;
	int X;
	string C;
	for (int i = 0; i < L; i++) {
		cin >> X >> C;
		command.push_back({ X, C });
	}

	deque<XY> snake = { {0, 0} };
	int time = 0, idx = 0;
	while (true) {
		XY front = snake.front();
		int dir = angle / 90;
		//cout << "현재 각도: " << dir << "\n";
		int nx = front.x + dx[dir], ny = front.y + dy[dir];
		// 벽에 부딛혔는지 확인
		if (nx >= N || nx < 0 || ny >= N || ny < 0) break;

		// 자기 자신과 부딛혔는지 확인
		bool collided = false;
		for (const auto& s : snake) {
			if (s.x == nx && s.y == ny) {
				collided = true;
				break;
			}
		}
		if (collided) break;

		snake.push_front({ nx, ny });

		// 머리가 위치한 칸에 사과가 있는지 확인
		if (grid[nx][ny] != 1) {
			// 없다면 꼬리를 제거
			snake.pop_back();
		}
		else {
			grid[nx][ny] = 0;
		}


		time++;

		// 시간이 끝나고 커멘드를 확인
		if (idx < L && command[idx].num == time) {
			Cell cmd = command[idx++];
			angle += DIRECTION[cmd.ch];
			angle = (360 + angle) % 360;
		}
		//cout << time << ", " << angle << ", 현재 좌표: (" << nx << ", " << ny << ")\n";
	}
	cout << ++time << "\n";
	return 0;
}