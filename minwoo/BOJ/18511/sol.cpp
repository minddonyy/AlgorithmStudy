#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n, k, l, ans;
vector<int> v;

void dfs(int depth, int res) {
	if (res > n) return;
	ans = max(ans, res);
	if (depth == l) {
		return;
	}
	for (int i = 0; i < k; i++) {
		dfs(depth + 1, res + (v[i] * pow(10, depth)));
	}
	return;
}

void solve() {
	cin >> n >> k;
	v.resize(k);
	for (int i = 0; i < k; ++i) cin >> v[i];
	for (int i = 1; i < 9; ++i) {
		int temp = n / pow(10, i);
		if (temp == 0) {
			l = i;
			break;
		}
	}
	dfs(0, 0);
	cout << ans << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	solve();
	return 0;
}