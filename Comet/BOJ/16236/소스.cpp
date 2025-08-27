using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
// 가독성을 위한 상수 지정
const int SHARK = 9;
// 입력변수
int length;
vector<vector<int>> arr;
// 상어 데이터;
int shark_size = 2; // 초기 사이즈 2
int eat_cnt = 0;	// 물고기 섭취 횟수
int y, x;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { -1, 1, 0, 0 };
struct coordinate
{
	int y, x;
};
bool compare(coordinate& a, coordinate& b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}
int find_and_eat() {
	vector<vector<bool>> visited(length, vector<bool>(length, 0));
	queue<coordinate> que;
	vector<coordinate> fishes;
	que.push({ y, x });
	visited[y][x] = 1;
	coordinate cur;
	int ny, nx;
	int leng = 0;
	while (!que.empty())
	{	
		
		int size = que.size();
		for (int repeat = 0; repeat < size; ++repeat) {
			cur = que.front(); que.pop();
			if (arr[cur.y][cur.x] >= 1 && arr[cur.y][cur.x] < shark_size) {
				fishes.push_back(cur);
				continue;
			}
			else if (arr[cur.y][cur.x] > shark_size){
				continue;
			}
			for (int i = 0; i < 4; ++i) {
				ny = cur.y + dy[i]; nx = cur.x + dx[i];
				if (ny < 0 || ny >= length || nx < 0 || nx >= length || visited[ny][nx] == 1) continue;
				visited[ny][nx] = 1;
				que.push({ ny, nx});
			}
		}
		if (fishes.size() != 0) {
			sort(fishes.begin(), fishes.end(), compare);
			y = fishes[0].y; x = fishes[0].x;
			//cout << y << ' ' << x << ' ' << shark_size << endl;
			arr[y][x] = 0;
			
			return leng;
		}
		leng++;
	}
	return 0;
}
int main()
{	
	int time = 0;
	cin >> length;
	arr.resize(length, vector<int>(length));
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == SHARK) {
				arr[i][j] = 0;
				y = i;
				x = j;
			}
		}
	}
	while (true)
	{	
		int ret = find_and_eat();
		if ( ret == 0) {
			break;
		}
		else {
			++eat_cnt;
			if (eat_cnt == shark_size) {
				eat_cnt = 0;
				shark_size += 1;
			}
		}
		time += ret;
	}
	cout << time << '\n';
	return 0;
}