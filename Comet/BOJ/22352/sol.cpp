using namespace std;
#include <iostream>
#include <vector>
#include <deque>
int row, col;
int before[30][30];
int after[30][30];
int cnt = 0;
int visited[30][30] = { 0 };
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
struct yx
{
	int y, x;
};
void bfs(int y, int x) {
	deque<yx> que;
	que.push_back({ y, x });
	visited[y][x] = 1;
	vector<yx> memo; memo.push_back({ y, x });
	yx cur;
	int tempy, tempx;
	while (!que.empty())
	{
		cur = que.front(); que.pop_front();

		for (int i = 0; i < 4; ++i) {
			tempy = cur.y + dy[i]; tempx = cur.x + dx[i];
			if (tempy < 0 || tempy >= row || tempx < 0 || tempx >= col || visited[tempy][tempx]) continue;
			if (before[tempy][tempx] == before[y][x]) {
				que.push_back({ tempy , tempx });
				memo.push_back({ tempy, tempx });
				visited[tempy][tempx] = 1;
			}
		}
	}
	int change = after[y][x];
	for (auto& cur : memo) {
		before[cur.y][cur.x] = change;
	}
}

bool find() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (before[i][j] != after[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}




int main() {
	cin >> row >> col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> before[i][j];
		}
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> after[i][j];
		}
	}
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (!visited[i][j] && before[i][j] != after[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	if (cnt >= 2 || find() == 0) {
		cout << "NO" << '\n';
	}
	else {
		cout << "YES" << '\n';
	}

}