#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
int v[109];
vector<int> ans;

// 현재 집합을 표현할 변수가 필요

void dfs(int startIndex, int curIndex, vector<bool>& visit) {
	visit[curIndex] = true;
	if (v[curIndex] == startIndex) {
		ans.push_back(startIndex);
		visit[curIndex] = false;
		return;
	}
	int nextIndex = v[curIndex];

	if (!visit[nextIndex])
		dfs(startIndex, nextIndex, visit);
	visit[curIndex] = false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];
	for (int k = 1; k <= n; ++k) {
		vector<bool> visit(n + 1, 0);
		dfs(k, k, visit);
	}
	cout << ans.size() << "\n";
	sort(ans.begin(), ans.end());
	for (const int& n : ans) {
		cout << n << "\n";
	}

	return 0;
}