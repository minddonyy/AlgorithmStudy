using namespace std;
#include <iostream>
#include <string>
string fir, sec, tar;
int dp[201][201];
bool dfs(int i, int j) {
	if (i == fir.size() && j == sec.size()) {
		return 1;
	}
	if (dp[i][j] != - 1) return dp[i][j];
	if (i < fir.size() && fir[i] == tar[i + j] && dfs(i + 1, j)) {
		dp[i][j] = 1;
		return 1;
	} else if (j < sec.size() && sec[j] == tar[i + j] && dfs(i, j + 1)) {
		dp[i][j] = 1;
		return 1;
	}
	dp[i][j] = 0;
	return 0;
}
int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> fir >> sec >> tar;

		for (int i = 0; i <= 200; i++) {
			for (int j = 0; j <= 200; j++) {
				dp[i][j] = -1;
			}
		}
		if (dfs(0, 0)) {
			cout << "Data set " << tc << ": " << "yes" << '\n';
		}
		else {
			cout << "Data set " << tc << ": " << "no" << '\n';
		}
	}
	return 0;
}