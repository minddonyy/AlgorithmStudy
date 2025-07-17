#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*

1. 여러 단원을 융합한 문제는 출제하지 않는다
2. 한 단원에 한 문제를 출제한다.

각 단원 별 배점을 적어 놓았다.
어떤 단원의 문제를 맞추기 위해서는 그 단원의 예상 공부시간만큼
혹은 그보다 더 많이 공부하면 맞출 수 있다고 가정
남은 시간동안 공부해서 얻을 수 있는 최대 점수를 구하는 프로그램
N <= 100
*/

int n, t;


struct Data {
	// 각 단원별 예상 공부 시간 k, 그 단원 문제의 배점 s
	int k, s;
};

void solve() {
	cin >> n >> t;
	vector<Data> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].k >> v[i].s;
	long res = -1;
	vector<vector<int>> dp(n + 1, vector<int>(t + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			int x = j - v[i - 1].k;
			if (x >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][x] + v[i - 1].s);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][t] << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}