#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

void input(vector<vector<int>>& array, int n, int m) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> array[i][j];
	return;
}

void run(
	vector<vector<int>>& a,
	vector<vector<int>>& b) {
	for (int n = 0; n < N; n++) {
		for (int k = 0; k < K; k++) {
			int temp = 0;
			for (int m = 0; m < M; m++)
				temp += a[n][m] * b[m][k];
			cout << temp << (k == K - 1 ? "\n" : " ");
		}
	}
	return;
}

void solve() {
	cin >> N >> M;
	vector<vector<int>> A(N, vector<int>(M));
	input(A, N, M);

	cin >> M >> K;
	vector<vector<int>> B(M, vector<int>(K));
	input(B, M, K);

	run(A, B);
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	solve();
	return 0;
}