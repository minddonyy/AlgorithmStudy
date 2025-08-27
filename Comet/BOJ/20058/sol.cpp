using namespace std;
#include <iostream>
#include <vector>
#include <queue>
int N, Q, length;
vector<vector<int>> arr;
vector<int> firestorms;
vector<vector<bool>> visited;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
struct yx
{   
	int y, x;
};
int calculate(int n) {
	int num = 1;
	for (int i = 0; i < n; ++i) {
		num *= 2;
	}
	return num;
}
void print() {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
void use_firestorm(int size) {
	// 격자 이동
	vector<vector<int>> newArr(length, vector<int>(length));
	for (int i = 0; i < length; i += size) {
		for (int j = 0; j < length; j += size) {
			// 벡터 순회 및 회전.
			for (int y = 0; y < size; ++y) {
				for (int x = 0; x < size; ++x) {
					newArr[i + y][j + x] = arr[i + size - x - 1][j + y];
				}
			}
		}
	}

	swap(arr, newArr);
	
}
void ice_breaking() {
	vector<yx> melts;
	int ny, nx;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (arr[i][j] == 0) continue;
			int cnt = 0;
			for (int k = 0; k < 4; ++k) {
				ny = i + dy[k]; nx = j + dx[k];
				if (ny < 0 || ny >= length || nx < 0 || nx >= length || arr[ny][nx] == 0) continue;
				cnt += 1;
			}
			if (cnt < 3) {
				melts.push_back({ i, j });
			}
		}
	}
	for (auto& melt : melts) {
		arr[melt.y][melt.x] -= 1;
	}
}
int find(int y, int x) {
	int cnt = 1;
	queue<yx> que;
	yx cur;
	que.push({ y, x });
	visited[y][x] = 1;
	int ny, nx;
	while (!que.empty())
	{
		cur = que.front(); que.pop();
		for (int k = 0; k < 4; ++k) {
			ny = cur.y + dy[k]; nx = cur.x + dx[k];
			if (ny < 0 || ny >= length || nx < 0 || nx >= length || visited[ny][nx] == 1 || arr[ny][nx] == 0) continue;
			cnt += 1;
			visited[ny][nx] = 1;
			que.push({ ny, nx });
		}
	}
	return cnt;
}


int main()
{
	// 입력 받기
	cin >> N >> Q;
	// 2 ^ N 승 구하기
	length = calculate(N);
	// 얼음 배열 입력 받기
	arr.resize(length, vector<int>(length));
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cin >> arr[i][j];
		}
	}
	// 파이어스톰 규모들 입력.
	int input;
	for (int i = 0; i < Q; ++i) {
		cin >> input;
		firestorms.push_back(input);
	}
	//print();

	for (int& firestorm_size : firestorms) {

		if (firestorm_size > 0) {
			use_firestorm(calculate(firestorm_size));
		}
		ice_breaking();
		//print();
	}

	int total_ice = 0;
	int max_ice = 0;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			total_ice += arr[i][j];
		}
	}

	visited.resize(length, vector<bool>(length, 0));
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (visited[i][j] == 1 || arr[i][j] == 0) continue;
			int ret = find(i, j);
			if (max_ice < ret) {
				max_ice = ret;
			}
		}
	}

	cout << total_ice << '\n' << max_ice << '\n';

	return 0;
}