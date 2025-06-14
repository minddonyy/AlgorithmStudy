using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

int low, col;
vector<string> flag;
vector<string> flagA;
vector<string> flagB;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
bool change(int y, int x) {
	vector<vector<bool>> visited(low, vector<bool>(col, 0));
	visited[y][x] = 1;
	queue<pair<int, int>> que; que.push(make_pair(y, x));
	pair<int, int> current;
	int tempy, tempx;
	flag[y][x] = flagB[y][x];
	while (que.size() != 0)
	{
		current = que.front(); que.pop();
		for (int i = 0; i < 4; i++) {
			tempy = current.first + dy[i]; tempx = current.second + dx[i];
			if (tempy >= 0 && tempy < low && tempx >= 0 && tempx < col && !visited[tempy][tempx] && flagA[y][x] == flagA[tempy][tempx]) {
				flag[tempy][tempx] = flagB[y][x];
				visited[tempy][tempx] = 1;
				que.push(make_pair(tempy, tempx));
				if (flag[tempy][tempx] != flagB[tempy][tempx]) return 0;
			}
		}
	}
	return 1;
}

string solve() {
	cin >> low >> col;
	string input;
	for (int i = 0; i < low; i++) {
		cin >> input;
		flagA.push_back(input);
		flag.push_back(input);
	}
	for (int i = 0; i < low; i++) {
		cin >> input;
		flagB.push_back(input);
	}
	for (int i = 0; i < low; i++) {
		for (int j = 0; j < col; j++) {
			if (flag[i][j] != flagB[i][j] && change(i, j) == 0) {
				return "NO";
			}
		}
	}
	return "YES";
}
int main() {
	cout << solve() << '\n';
	return 0;
}