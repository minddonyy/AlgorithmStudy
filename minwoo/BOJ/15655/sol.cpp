#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
n개의 자연수와 자연수 m
n개의 자연수 중에서 m개를 고른 수열
고른 수열은 오름차순
중복되는 수열을 여러 번 출력하면 안됨
*/
int n, m;
vector<int> v;

void dfs(int depth, int idx, vector<int>& r) {
	if (depth == m) {
		for (int i = 0; i < m; ++i)
			cout << r[i] << (i == m - 1 ? "\n" : " ");
		return;
	}
	for (int i = idx; i < n; ++i) {
		r.push_back(v[i]);
		dfs(depth + 1, i + 1, r);
		r.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	vector<int> empty;
	dfs(0, 0, empty);
	return 0;
}