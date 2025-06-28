#include <iostream>
using namespace std;

long long int dp[100];

void solve(int n) {
	long long int num;
	for (int i = 1; i <= n; i++) {
		num = 0;
		for (int j = 0; j < i; j++) {
			num += (dp[j] * dp[i - (1 + j)]);
		}
		dp[i] = num;
	}
}

int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	solve(n);
	cout << dp[n] << "\n";
	return 0;
}