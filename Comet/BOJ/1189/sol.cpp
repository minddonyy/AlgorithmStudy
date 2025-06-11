#include <iostream>
using namespace std;
#include <vector>
#include <string>

int result;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int low, col, length;
void dfs(int y, int x, int cnt,vector<vector<bool>>& visited, vector<string>& map) {
	if (y == 0 && x == col - 1) {
		if (cnt == length) {
			result++;
		}
		return;
	}
	if (cnt >= length) return;
	int tempy, tempx;
	for (int i = 0; i < 4; i++) {
		tempy = y + dy[i]; tempx = x + dx[i];
		if (tempy >= 0 && tempy < low && tempx >= 0 && tempx < col && map[tempy][tempx] != 'T' && !visited[tempy][tempx]) {
			visited[tempy][tempx] = 1;
			dfs(tempy, tempx, cnt + 1, visited, map);
			visited[tempy][tempx] = 0;
		}

	}
	return;
}



int main() {
	result = 0;
	
	cin >> low >> col >> length;
	vector<string> map(low);
	vector<vector<bool>> visited(low, vector<bool>(col, 0));
	for (int i = 0; i < low; i++) {
		cin >> map[i];
	}
	visited[low - 1][0] = 1;
	dfs(low - 1, 0, 1,visited, map);
	cout << result << '\n';
	return 0;
}