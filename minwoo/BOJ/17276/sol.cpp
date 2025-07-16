#include <iostream>
#include <vector>
using namespace std;

int n, d;

/*

	아래 예시는 시계 방향으로 회전할 때
	x의 주 대각선(1, 1) ~ (n, n)을 가운데 열( (n+1) / 2 번째 열)로 옮긴다
	x의 가운데 열을 부 대각선 (n, 1) ~ (1, n)으로 옮긴다
	x의 부 대각선을 가운데 행( (n+1) / 2 번째 행)으로 옮긴다
	x의 가운데 행을 주 대각선으로 옮긴다.

*/

void cw(vector<vector<int>>& v) {
	vector<int> main_diag(n);
	vector<int> sub_diag(n);
	vector<int> mid_row(n);
	vector<int> mid_col(n);
	int j = ((n + 1) / 2) - 1;

	for (int i = 0; i < n; i++) {
		main_diag[i] = v[i][i];
		sub_diag[i] = v[i][n - 1 - i];
		mid_col[i] = v[i][j];
		mid_row[i] = v[j][i];
	}

	for (int i = 0; i < n; i++) {
		v[i][j] = main_diag[i]; // 세로 <- 주 대각
		v[i][i] = mid_row[i];	// 주 대각 <- 가로
		v[j][i] = sub_diag[n - 1 - i];	// 가로 <- 부 대각(끝부터 역순으로)
		v[i][n - 1 - i] = mid_col[i];	// 부 대각 <- 세로
	}

	return;
}

void ccw(vector<vector<int>>& v) {
	vector<int> main_diag(n);
	vector<int> sub_diag(n);
	vector<int> mid_row(n);
	vector<int> mid_col(n);
	int j = ((n + 1) / 2) - 1;

	for (int i = 0; i < n; i++) {
		main_diag[i] = v[i][i];
		sub_diag[i] = v[i][n - 1 - i];
		mid_col[i] = v[i][j];
		mid_row[i] = v[j][i];
	}

	for (int i = 0; i < n; i++) {
		v[i][j] = sub_diag[i]; // 세로 <- 부 대각
		v[i][i] = mid_col[i];	// 주 대각 <- 세로
		v[j][i] = main_diag[i];	// 가로 <- 주 대각
		v[i][n - 1 - i] = mid_row[n - 1 - i];	// 부 대각 <- 가로(역순으로)
	}

	return;
}

void solve() {
	cin >> n >> d;
	vector<vector<int>> v(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	int r = d >= 0 ? 1 : -1;
	for (int k = 0; k < (d % 360) / (45 * r); k++) {
		if (r == 1)
			cw(v);
		else
			ccw(v);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << v[i][j] << (j == n - 1 ? "\n" : " ");
	
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
		solve();
	return 0;
}