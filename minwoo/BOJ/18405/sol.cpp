#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, K, S, X, Y;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
struct XY { int x; int y; };

void bfs(vector<vector<int>>& grid, vector<XY>& vq, int num) {
    vector<XY> moving_virus;
    for (int i = 0; i < vq.size(); i++) {
        int x = vq[i].x, y = vq[i].y;
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= N || nx < 0 || ny >= N || ny < 0 || grid[nx][ny] != 0) continue;
            grid[nx][ny] = num;
            moving_virus.push_back({ nx, ny });
        }
    }
    vq = moving_virus;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    FILE* fp;
    freopen_s(& fp, "input.txt", "r", stdin);

    cin >> N >> K;
    // 각 바이러스를 map으로 저장, map의 자료형은 vector
    unordered_map<int, vector<XY>> virus;
    // 시험관 크기 설정
    vector<vector<int>> grid(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            int acc = grid[i][j];
            if (acc > 0) virus[acc].push_back({ i, j });
        }
    }

    cin >> S >> X >> Y;

    // S초 뒤에 (x, y)에 존재하는 바이러스 종류, 없다면 0
    for (int time = 0; time < S; time++) {
        for (int k = 1; k <= K; k++) {
            bfs(grid, virus[k], k);
        }
    }
    cout << grid[X-1][Y-1] << "\n";

    return 0;
}