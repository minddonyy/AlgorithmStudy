using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
int result;


void solve() {
	int num, length; cin >> num >> length;
	vector<vector<int>> arr(num, vector<int>(3));
	vector<int> dp(length + 1, 0 );
	for (int i = 0; i < num; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
	}
	sort(arr.begin(), arr.end(), [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1]; });
	arr.push_back({ -1, -1, -1 });

	int pointer = 0;
	for (int i = 1; i <= length; i++) {
		if (arr[pointer][1] == i) {
			dp[i] = min({ dp[i - 1] + 1, dp[arr[pointer][0]] + arr[pointer][2]});
			pointer++;
			while (arr[pointer][1] == i) {
				dp[i] = min({ dp[i - 1] + 1, dp[arr[pointer][0]] + arr[pointer][2], dp[i] });
				pointer++;
			}
		}
		else {
			dp[i] = dp[i - 1] + 1;
		}
	}
	result = dp[length];
}
int main() {
	solve();
	cout << result << '\n';
	return 0;
}
