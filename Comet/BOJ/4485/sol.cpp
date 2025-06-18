using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
int length, result, tc = 0;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
void solve() {
	vector<vector<int>> map(length, vector<int>(length));
	vector<vector<int>> dijkstra(length, vector<int>(length, 999999999));
	queue<pair<int, int>> que;
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cin >> map[i][j];
		}
	}
	dijkstra[0][0] = map[0][0];
	que.push(make_pair(0, 0));
	pair<int, int> current;
	int tempy, tempx;
	while (que.size() > 0)
	{
		current = que.front(); que.pop();
		for (int i = 0; i < 4; i++) {
			tempy = current.first + dy[i]; tempx = current.second + dx[i];
			if (tempy >= 0 && tempy < length && tempx >= 0 && tempx < length && dijkstra[current.first][current.second] + map[tempy][tempx] < dijkstra[tempy][tempx]) {
				que.push(make_pair(tempy, tempx));
				dijkstra[tempy][tempx] = dijkstra[current.first][current.second] + map[tempy][tempx];

			}
		}
	}
	result = dijkstra[length - 1][length - 1];
}
int main() {
	while (true)
	{	
		tc++;
		cin >> length;
		if (length == 0) break;
		solve();
		cout << "Problem " << tc << ": " << result << '\n';
	}
	return 0;
}