using namespace std;
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
int num;
int arr[101];
bool visited[101] = { 0 };
bool same[101] = { 0 };
int sameCnt = 0;
int memo;
set<int> ans;
set<int> temp;
bool dfs(int n) {
	if (visited[n] || same[n]) {
		if (n != memo) return 0;
		ans.insert(temp.begin(), temp.end());
		return 1;
	}
	visited[n] = 1;
	temp.insert(n);
	if (!dfs(arr[n])) {
		visited[n] = 0;
		return 0;
	}
	return 1;
}
int main() {
	cin >> num;
	for (int i = 1; i <= num; ++i) {
		cin >> arr[i];
		if (i == arr[i]) {
			++sameCnt;
			same[i] = 1;
		}
	}
	for (int i = 1; i <= num; ++i) {
		if (same[i] || visited[i]) continue;
		memo = i;
		temp.clear();
		memset(visited, 0, sizeof(visited));
		dfs(i);
	}
	for (int i = 1; i <= num; ++i) {
		if (same[i]) {
			ans.insert(i);
		}
	}
	cout << ans.size() << '\n';
	for (int i : ans) {
		cout << i << '\n';
	}
	return 0;

}