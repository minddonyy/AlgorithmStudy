using namespace std;
#include <iostream>
#include <algorithm>
#include <deque>
#include <unordered_set>
int arr[1000][1000];
int mapping[1000][1000];
bool visited[1000][1000];
int shape[1000000] = { 0 };
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };
int row, col, idx = 0;

struct dataset
{
	int y, x;
};
deque<dataset> que;
void bfs(int y, int x) {
	que.clear();
	que.push_back({ y, x });
	int tempy, tempx, val = 0;
	dataset cur;
	visited[y][x] = 1;
	val++;
	idx++;
	mapping[y][x] = idx;
	while (!que.empty())
	{
		cur = que.front(); que.pop_front();
		for (int i = 0; i < 4; ++i) {
			tempy = cur.y + dy[i]; tempx = cur.x + dx[i];
			if (tempy < 0 || tempy >= row || tempx < 0 || tempx >= col || visited[tempy][tempx] || !arr[tempy][tempx]) continue;
			que.push_back({ tempy, tempx});
			visited[tempy][tempx] = 1;
			++val;
			mapping[tempy][tempx] = idx;
		}
	}
	shape[idx] = val;
	return ;
}
int main() {
	cin >> row >> col;
	int result = -1;
	// 입력 받기
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> arr[i][j];
		}
	}
	//매핑
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				bfs(i, j);
			}
			
		}
	}
	int tempy, tempx;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (arr[i][j] == 1) continue;
			unordered_set<int> select;
			int temp = 1;
			for (int k = 0; k < 4; ++k) {
				tempy = i + dy[k]; tempx = j + dx[k];
				if (tempy < 0 || tempy >= row || tempx < 0 || tempx >= col || arr[tempy][tempx] == 0) continue;
				select.insert(mapping[tempy][tempx]);
			}
			for (auto& n : select) {
				temp += shape[n];
			}
			result = max(result, temp);
		}
	}
	cout << result << '\n';
	return 0;
}