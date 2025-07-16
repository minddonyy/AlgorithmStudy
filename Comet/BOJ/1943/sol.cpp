using namespace std;
#include <iostream>
#include <cstring>
#include <vector>


int coins[100];
int nums[100];
bool dp[50001];
int memo[50001];
void solve() {
	memset(dp, 0, sizeof(dp));
	int N; cin >> N;
	int target = 0;
	for (int i = 0; i < N; ++i) {
		cin >> coins[i]; cin >> nums[i];
		target += coins[i] * nums[i];
	}
	if (target % 2 == 1) {
		cout << 0 << '\n';
		return;
	}
	dp[0] = 1;
	target /= 2;
	int coin;
	int num;
	int diff;
	for (int i = 0; i <= N; ++i) {
		coin = coins[i];
		num = nums[i];

		vector<int> memo(target + 1, 0);
		for (int k = coin; k <= target; ++k) {
			if (dp[k]) {
				continue;
			}
			diff = k - coin;
			if (dp[diff] == 1 && memo[diff] < num) {
				dp[k] = 1;
				memo[k] = memo[diff] + 1;
			}
		}
	}
	if (dp[target] == 1) {
		cout << 1 << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}

}



int main() {
	for (int tc = 0; tc < 3; tc++) {
		solve();
	}

	return 0;
}