#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;


void printGrid(const vector<string>& grid) {
	for (const string& row : grid) {
		cout << row << '\n';
	}
	cout << "-------------------\n";
}



int N, M;
vector<string> A;
vector<string> B;
vector<vector<bool>> visited;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0,  -1 };


void bfs(int sx, int sy, char color) {
	deque<pair<int, int>> dq;
	dq.push_back({ sx, sy });
	vector<pair<int, int>> coord;
	coord.push_back({ sx, sy });
	visited[sx][sy] = true;
	while (dq.size()) {
		pair<int, int> front = dq.front();
		dq.pop_front();
		
		int x = front.first;
		int y = front.second;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k], ny = y + dy[k];
			if (nx >= N || nx < 0 || ny >= M || ny < 0) continue;
			if (visited[nx][ny] || (A[nx][ny] != A[sx][sy])) continue;
			coord.push_back({ nx, ny });
			dq.push_back({ nx, ny });
			visited[nx][ny] = true;
		}
	}
	// 색 바꾸기
	for (auto& now : coord) {
		int x = now.first;
		int y = now.second;

		A[x][y] = color;
	}
	return;
}

int main() {
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	cin >> N >> M;
	cin.ignore();
	string temp;
	for (int i = 0; i < N; i++) {
		getline(cin, temp);
		A.push_back(temp);
	}
	for (int i = 0; i < N; i++) {
		getline(cin, temp);
		B.push_back(temp);
	}
	visited.resize(N, vector<bool>(M, false));
	// 국기의 격자판 중 한 칸을 고르고, 이 칸과 같은 구역에 속한 모든 칸을 찾는다.
	// 두 칸이 같은 색이면서, 상하좌우로 인접해 있을 경우 둘은 같은 구역에 속한다.
	// 해당하는 구역의 칸들의 색을 원하는 다른 색으로 바꾼다.
	// 이때 영어 알파벳 대문자 외에도 임이의 다른 색을 새로 사용할 수 있다.

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) continue;
			if (A[i][j] == B[i][j]) continue;
			bfs(i, j, B[i][j]);
			printGrid(A);  // 원하는 시점마다 호출
		}
	}

	printGrid(A);  // 원하는 시점마다 호출

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	cout << "YES" << "\n";
	return 0;
}