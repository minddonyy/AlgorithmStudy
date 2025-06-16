using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
int result = 0;
int  low, col;
int direc, y, x;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int tempy, tempx;
int rev[4] = { 2, 3, 0, 1 };
int rot[4] = { 3, 0, 1, 2 };

void solve() {
	cin >> low >> col;
	cin >> y >> x >> direc;
	vector<vector<int>> arr(low, vector<int>(col, 0));
	for (int i = 0; i < low; i++) {
		for (int j = 0; j < col; j++) {
			cin >> arr[i][j];
		}
	}
	int flag = 0;
	while (true)
	{	
		if (arr[y][x] == 0) {
			arr[y][x] = 2; // 현재 위치 청소
			result++;
		}
		flag = 0;
		for (int i = 0; i < 4; i++) {
			tempy = y + dy[i]; tempx = x + dx[i];
			if (tempy >= 0 && tempy < low && tempx >= 0 && tempx < col && arr[tempy][tempx] == 0) {
				flag = 1; break;
			}
		}
		if (flag) {
			direc = rot[direc]; tempy = y + dy[direc]; tempx = x + dx[direc];
			if (tempy >= 0 && tempy < low && tempx >= 0 && tempx < col && arr[tempy][tempx] == 0) {
				y = tempy; x = tempx;
			}
		}
		else
		{
			tempy = y + dy[rev[direc]]; tempx = x + dx[rev[direc]];
			if (tempy >= 0 && tempy < low && tempx >= 0 && tempx < col && (arr[tempy][tempx] == 0 || arr[tempy][tempx] == 2)) {
				y = tempy; x = tempx;
			}
			else {
				break;
			}
		}
	}


}
int main() {
	solve();
	cout << result << '\n';
	return 0;
}
