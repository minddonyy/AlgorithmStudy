#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MAX = 100000;
bool visited[MAX + 1];

int A, B, N, M;

int bfs() {
	deque<pair<int, int>> dq;
	dq.push_back({ N, 0 });
	visited[N] = true;

	while (!dq.empty()) {

		pair<int, int> front = dq.front();
		dq.pop_front();

		int now = front.first;
		int cnt = front.second;

		if (now == M) return cnt;

		vector<int> moves = {
			now + 1, now - 1,
			now + A, now - A,
			now + B, now - B,
			now * A, now * B
		};
		for (int nx : moves) {
			if (nx < 0 || nx > MAX) continue;
			if (visited[nx]) continue;
			visited[nx] = true;
			dq.push_back({ nx, cnt + 1 });
		}
	}
	return -1;
}


int main() {
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> N >> M;
	
	int result = bfs();
	cout << result << '\n';

	return 0;
}