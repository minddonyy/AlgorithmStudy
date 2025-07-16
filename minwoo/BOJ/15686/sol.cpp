#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int result = 1e9;
struct XY { int x, y; };
vector<XY> store; 
vector<XY> home;

void dfs(int depth, vector<int> dist, int index, int len) {
	/*
		운영할 치킨집을 고른다

		종료조건
		- depth == M

		for문을 돌면서 현재까지 집 인덱스와 동일한 인덱스 위치에 해당 치킨 거리를 저장
		만약 새로 개업한 치킨 거리보다 작다면 이미 저장된 치킨거리를 갱신하면서
		갱신 전 후 값의 차만큼 더한다
	*/
	if (depth == M) {
		int sum_dist = 0;
		for (const int x : dist) sum_dist += x;
		result = min(result, sum_dist);
		return;
	}
	
	for (int i = index; i < len; i++) {
		XY cur = store[i];
		vector<int> nextDist = dist;
		int idx = 0;
		for (const XY h : home) {
			int now = abs(cur.x - h.x) + abs(cur.y - h.y);
			int& d = nextDist[idx++];
			if (now >= d) continue;
			d = now;
		}
		dfs(depth + 1, nextDist, i + 1, len);
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	cin >> N >> M;
	int n;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> n;
			if (n == 1) home.push_back({ i, j });
			else if (n == 2) store.push_back({ i,j });
		}
	}

	int len = store.size();
	int homeSize = home.size();
	dfs(0, vector<int>(homeSize, 1e8), 0, len);
	cout << result << "\n";
	return 0;
}