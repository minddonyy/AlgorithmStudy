using namespace std;
#include <iostream>
#include <vector>
#include <queue>
const int target = 100;

int result = 0;
int map[101] = { 0 };
int events[101] = { 0 };
bool visited[101] = { 0 };
int ladder, snake, l, s, cur, len;
queue<int> que;
void solve() {
	cin >> ladder >> snake;
	for (int i = 0; i < ladder + snake; i++) {
		cin >> l >> s;
		events[l] = s;
	}
	visited[1] = 1;
	que.push(1);
	while (true)
	{
		result++;
		len = que.size();
		for (int i = 0; i < len; i++) {
			cur = que.front(); que.pop();
			for (int j = 1; j <= 6; j++) {
				if (cur + j == 100) {
					return;
				}
				else if (cur + j < 100 && !visited[cur + j]) {
					if (events[cur + j]) {
						que.push(events[cur + j]);
						visited[cur + j] = 1; visited[events[cur + j]] = 1;
					}
					else
					{
						que.push(cur + j);
						visited[cur + j] = 1;
					}
				}
			}
		}
	}
	return;
}

int main() {
	solve();
	cout << result << '\n';
	return 0;
}
