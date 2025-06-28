#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N;
int beer;
const int MAX = 1000;

struct XY {
	int x;
	int y;
};


int bfs(vector<vector<int>>& edges, int E) {
	deque<int> pq;
	pq.push_back(0);
	vector<bool> visited(E, 0);
	visited[0] = true;
	while (!pq.empty()) {
		int cur = pq.front();
		if (cur == E - 1) return 1;
		pq.pop_front();

		for (auto nxt : edges[cur]) {
			if (visited[nxt] == true) continue;
			pq.push_back(nxt);
			visited[nxt] = true;
		}
	}
	return 0;
}



int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	int T;
	cin >> T;


	for (int tc = 0; tc < T; tc++) {
		// 편의점 개수 입력
		cin >> N;
		int E = N + 2;

		// 정점 입력
		vector<XY> store;
		int temp_x, temp_y;
		for (int n = 0; n < E; n++) {
			cin >> temp_x >> temp_y;
			store.push_back({ temp_x, temp_y });
		}

		// 각 정점에서 이동할 수 있으면 graph로 연결
		vector<vector<int>> edges(E);
		for (int i = 0; i < E; i++) {
			int ix = store[i].x, iy = store[i].y;
			for (int j = 0; j < E; j++) {
				int jx = store[j].x, jy = store[j].y;
				if ((abs(ix - jx) + abs(iy - jy)) <= MAX) {
					edges[i].push_back(j);
				}
			}
		}
		// BFS 탐색
		if (bfs(edges, E)) {
			cout << "happy" << "\n";
		}
		else {
			cout << "sad" << "\n";
		}
	}
	return 0;
}