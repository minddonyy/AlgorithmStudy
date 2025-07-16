using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
struct location
{
	int y, x;
};

vector<location> store;
vector<location> house;
bool visited[13];
vector<vector<int>> arr(100, vector<int>());
int length, max_num, result = 999999999;
int store_num, house_num;

void calculate() {
	int sum_val = 0, min_val; 
	for (int i = 0; i < house_num; i++) {
		min_val = 99999;
		for (int j = 0; j < store_num; j++) {
			if (visited[j] && min_val > arr[i][j]) {
				min_val = arr[i][j];
			}
		}
		sum_val += min_val;

	}

	if (result > sum_val) {
		result = sum_val;
	}
	
}
void dfs(int cnt, int choose) {
	if (choose == max_num) {
		calculate();
		return;
	}
	if (cnt == store_num) {
		return;
	}
	visited[cnt] = 1;
	dfs(cnt + 1, choose + 1);
	visited[cnt] = 0;
	dfs(cnt + 1, choose);
}


void solve() {
	cin >> length >> max_num;
	int _input;
	
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			cin >> _input;
			if (_input == 1) {
				house.push_back({ i, j });
			}
			else if (_input == 2) {
				store.push_back({ i, j });
			}
		}
	}
	house_num = house.size();
	store_num = store.size();

	for (int i = 0; i < house_num; i++) {
		for (int j = 0; j < store_num; j++) {
			arr[i].push_back(abs(house[i].y - store[j].y) + abs(house[i].x - store[j].x));
		}
	}


	dfs(0, 0);
	cout << result << '\n';
}


int main() {
	solve();
	return 0;
}