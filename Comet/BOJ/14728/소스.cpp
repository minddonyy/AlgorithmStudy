using namespace std;
#include <iostream>
#include <algorithm>
int solve() {
	int num, limit; cin >> num >> limit;
	int score[100], times[100];
	int dp[10001] = { 0 };
	int k, s;
	for (int i = 0; i < num; ++i) {
		cin >> k >> s;
		score[i] = s;
		times[i] = k;
	}
	for (int i = 0; i < num; ++i) {
		for (int j = limit; j >= times[i]; --j) {
			dp[j] = max(dp[j], dp[j - times[i]] + score[i]);
		}
	}
	return dp[limit];
}


int main() {
	int result = solve();
	cout << result << '\n';
	return 0;
}

