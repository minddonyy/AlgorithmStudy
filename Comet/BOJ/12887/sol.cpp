using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <deque>

struct yx
{
	int y, x, length;
};
int dy[3] = { 0,-1, 1 };
int dx[3] = { 1, 0, 0 };
int solve() {
	int row = 2, col; cin >> col;
	int cnt = col * 2;
	vector<string> arr(row);
	int visited[2][50] = { 0 };
	for (int i = 0; i < row; ++i) {
		cin >> arr[i];
		for (auto& ch : arr[i]) {
			if (ch == '#') cnt--;
		}
	}
	deque<yx> que; 
	if (arr[0][0] == '.') {
		que.push_back({ 0, 0, 1 });
		visited[0][0] = 1;
	}
	if (arr[1][0] == '.') {
		que.push_back({ 1, 0, 1 });
		visited[1][0] = 1;
	}
	
	
	yx cur;
	int tempy, tempx;

	while (!que.empty())
	{
		cur = que.front(); que.pop_front();
		if (cur.x == col - 1) {
			return cnt - cur.length;
			
		}
		for (int i = 0; i < 3; ++i) {
			tempy = cur.y + dy[i]; tempx = cur.x + dx[i];
			if (tempy < 0 || tempy >= row || tempx < 0 || tempx >= col || arr[tempy][tempx] == '#' || visited[tempy][tempx]) continue;
			visited[tempy][tempx] = 1;
			que.push_back({ tempy, tempx, cur.length + 1 });
		}
	}
	return 0;
}

int main() {
	int result = solve();

	cout << result << '\n';
	return 0;
}