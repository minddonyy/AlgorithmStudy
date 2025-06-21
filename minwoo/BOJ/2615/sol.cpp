#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 19;
int grid[N][N] = { 0 };
bool visited[N][N] = { 0 };
int dx[4]{ 0, 1, 1, 1 };
int dy[4]{ 1, 0, 1, -1 };
struct XY { int x; int y; };

bool check(int x, int y, vector<XY>& coord) {
	int color = grid[x][y];
	vector<XY> temp;
	for (int i = 0; i < 4; i++) {
		int cnt = 0;
		for (int k = 0; k < N; k++) {
			int nx = x + (dx[i] * k), ny = y + (dy[i] * k);
			if (nx >= N || nx < 0 || ny >= N || ny < 0 || grid[nx][ny] == 0) break;
			if (grid[nx][ny] != color) break;
			temp.push_back({ nx, ny });
			cnt++;
		}
		if (cnt == 5) {
			int px = x - dx[i], py = y - dy[i];
			bool prev_ok = (px >= N || px < 0 || py >= N || py < 0 || grid[px][py] != color);
			if (prev_ok) {
				coord = temp;
				return true;			}
		}
	}
	return false;
}

XY is_valid() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			if (grid[x][y] == 0) continue;
			// 가장 왼쪽 중 가장 높은 정점
			vector<XY> coord;
			if (check(x, y, coord)) {
				sort(coord.begin(), coord.end(), [](const XY& a, const XY& b) {
					if (a.y != b.y) return a.y < b.y;
					return a.x < b.x;
				});
				return { coord[0].x, coord[0].y };
			}
		}
	}
	return { -1, -1 };
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
		}
	}
	XY res = is_valid();
	if (res.x == -1 && res.y == -1) {
		cout << 0 << "\n";
		return 0;
	}
	cout << grid[res.x][res.y] << "\n";
	cout << res.x + 1 << " " << res.y + 1 << "\n";
	return 0;
}