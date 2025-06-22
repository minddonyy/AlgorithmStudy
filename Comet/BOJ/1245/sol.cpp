using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
int result = 0, row, col;
int arr[100][70];
bool visited[100][70];
bool search[100][70];
struct yx
{
	int y, x;
};
vector<yx> direc = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
int min(int a, int b) {
	if (a > b) {
		return a;
	}
	else
	{
		return b;
	}
}
bool dfs(int y, int x) {
	int tempy, tempx;
	bool flag = 1;
	search[y][x] = 1;


	for (int i = 0; i < 8; i++) {
		tempy = y + direc[i].y; tempx = x + direc[i].x;
		if (tempy >= 0 && tempy < row && tempx >= 0 && tempx < col && !visited[tempy][tempx]) {
			if (arr[tempy][tempx] == arr[y][x]) {
				visited[y][x] = 1;
				flag = min(dfs(tempy, tempx), flag);
			}
			else if (arr[tempy][tempx] > arr[y][x]) {
				flag = 0;
			}
		}
	}
	return flag;
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> row >> col;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			
			if (!search[i][j]) {
				memset(visited, 0, sizeof(visited)); visited[i][j] = 1;
				if (dfs(i, j)) {
					result++;

				}
				
			}
		}
	}
	cout << result << '\n';
	return 0;
}