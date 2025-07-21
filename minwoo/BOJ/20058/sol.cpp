#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

// 2^n * 2^n인 격자로 나누어진 얼음판
// r, c는 r행 c열, A[r][c]는 얼음 양을 의미(0인 경우는 얼음이 없는 경우)
/*
	시전하려면 시전할 때마다 단계 l을 결정해야 한다.
	1. 먼저 격자를 2^l x 2^l 크기의 부분 격자로 나눈다
	2. 모든 부분 격자를 시계 방향으로 90도 회전시킨다.
	3. 얼음이 있는 칸 3개 또는 그 이상과 인접해있지 않은 칸은 얼음의 양이
		1 줄어든다.
		=> 어떤 칸에서 인접한 칸의 얼음이 있는 수가 3개 미만일 경우
	r, c와 인접한 칸은 (r-1,c), (r+1, c), (r, c-1), (r, c+1)이다

	파이어스톰을 총 q번 시전하려고 한다
	다음 2가지를 구한다
	1. 남아있는 A[r][c]의 합
	2. 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
	(단, 덩어리가 없으면 0을 출력한다.)
*/

int n, q, l, k;
vector<vector<int>> a;

void rotate_array(int r_start, int c_start, int grid_size) {
	vector<vector<int>> v(grid_size, vector<int>(grid_size));
	//cout << r_start << ", " << c_start << "시작\n";
	// 1. 복사
	for (int i = 0; i < grid_size; ++i)
		for (int j = 0; j < grid_size; ++j)
			v[i][j] = a[r_start + i][c_start + j];

	// 2. 덮어쓰기
	for (int i = 0; i < grid_size; ++i)
		for (int j = 0; j < grid_size; ++j)
			a[r_start + j][c_start + grid_size - 1 - i] = v[i][j];
	return;
}

// 2*l을 만족하는 범위까지 도달하는 함수
void firestorm_rotate(int cur_l_level, int r, int c, int grid_size) {
	if (cur_l_level == l) {
		rotate_array(r, c, grid_size);
		return;
	}

	int half_gird_size = grid_size / 2;

	firestorm_rotate(cur_l_level - 1, r, c, half_gird_size);
	firestorm_rotate(cur_l_level - 1, r, c + half_gird_size, half_gird_size);
	firestorm_rotate(cur_l_level - 1, r + half_gird_size, c, half_gird_size);
	firestorm_rotate(cur_l_level - 1, r + half_gird_size, c + half_gird_size, half_gird_size);
	return;
}

//void print_array() {
//	for (int i = 0; i < k; ++i)
//		for (int j = 0; j < k; ++j)
//			cout << a[i][j] << (j == k - 1 ? "\n" : " ");
//	return;
//}

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void check_neighborhood_is_ice() {
	vector<vector<int>> temp_vector = a;
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < k; ++j) {
			if (a[i][j] <= 0) continue;
			int cnt = 0;
			for (int x = 0; x < 4; ++x) {
				int nx = i + dx[x], ny = j + dy[x];
				if (nx >= k || nx < 0 || ny >= k || ny < 0) continue;
				if (a[nx][ny] == 0) continue;
				cnt++;
			}
			if (cnt < 3) temp_vector[i][j] -= 1;
		}
	a = temp_vector;
	return;
}

struct Node { int x, y; };

int check_ice_block(int stx, int sty, vector<vector<bool>>& visited) {
	queue<Node> q;
	q.push({ stx, sty });
	visited[stx][sty] = true;
	int cnt = 1;
	while (!q.empty()) {
		Node cur = q.front(); q.pop();
		for (int t = 0; t < 4; ++t) {
			int nx = cur.x + dx[t], ny = cur.y + dy[t];
			if (nx >= k || nx < 0 || ny >= k || ny < 0) continue;
			if (visited[nx][ny] || a[nx][ny] == 0) continue;
			q.push({ nx, ny });
			visited[nx][ny] = true;
			cnt++;
		}
	}
	return cnt;
}

void solve() {
	// 1. 분할정복으로 2^l까지 도달
	// 2. 2^l에서 배열 돌리기(복사 -> 다시 쓰기)
	// 3. 인접칸에 얼음 존재 확인
	// 1 2 3 q번 반복
	for (int p = 0; p < q; ++p) {
		cin >> l;
		//cout << "===================\n실행\n";
		firestorm_rotate(n, 0, 0, k);
		// 인접 칸에 얼음이 없는 칸이 2칸 이상이라면, 해당 칸 - 1
		check_neighborhood_is_ice();
		//print_array();
	}
	//cout << "===============\n";
	// 남아있는 얼음 A[r][c]의 합
	int leftover_ice = 0, max_ice_size = -1;
	vector<vector<bool>> visited(k, vector<bool>(k));
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < k; ++j) {
			leftover_ice += a[i][j];
			if (!visited[i][j] && a[i][j] != 0) {
				max_ice_size = max(max_ice_size, check_ice_block(i, j, visited));
			}
		}
			
	// 남아있는 얼음이 없다면
	if (max_ice_size < 0) {
		leftover_ice = 0;
		max_ice_size = 0;
	}
	cout << leftover_ice << "\n" << max_ice_size << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> n >> q;
	k = pow(2, n);
	a = vector<vector<int>>(k, vector<int>(k));
	for (int i = 0; i < k; ++i)
		for (int j = 0; j < k; ++j)
			cin >> a[i][j];
	solve();
	return 0;
}