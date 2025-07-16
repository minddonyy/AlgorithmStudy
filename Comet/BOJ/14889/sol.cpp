using namespace std;
#include <iostream>
#include <vector>
#include <cmath>

int num, result = 9999999, limit;
vector<vector<int>> arr(20, vector<int>(20));
bool visited[20] = { 0 };
void calculate() {
	int start = 0, link = 0, diff;
	vector<int> startteam, linkteam;
	for (int i = 0; i < num; i++) {
		if (visited[i]) {
			startteam.push_back(i);
		}
		else {
			linkteam.push_back(i);
		}
	}
	for (int i = 0; i < startteam.size(); i++) {
		for (int j = i + 1; j < startteam.size(); j++) {
			start += arr[startteam[i]][startteam[j]]; start += arr[startteam[j]][startteam[i]];
		}
	}
	for (int i = 0; i < linkteam.size(); i++) {
		for (int j = i + 1; j < linkteam.size(); j++) {
			link += arr[linkteam[i]][linkteam[j]]; link += arr[linkteam[j]][linkteam[i]];
		}
	}
	diff = abs(start - link);
	if (diff < result) {
		result = diff;
	}
}
void dfs(int cnt, int choose) {
	if (choose == limit) {
		calculate();
		return;
	}
	if (cnt == num) {
		return;
	}
	visited[cnt] = 1;
	dfs(cnt + 1, choose + 1);
	visited[cnt] = 0;
	dfs(cnt + 1, choose);
}

int main() {
	cin >> num; limit = num / 2;
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cin >> arr[i][j];
		}
	}
	dfs(0, 0);
	cout << result << '\n';
	return 0;
}