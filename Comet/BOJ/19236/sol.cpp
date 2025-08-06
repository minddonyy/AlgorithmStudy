using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>





const int length = 4;
const int SHARK = -1;
const int die = 0;
int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int result = 0;
struct dataset
{
	int y, x, direc;
	bool live = 1;
};
void print(vector<vector<int>>& arr) {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}
// 이동 가능위치 반환 함수.
vector<dataset> find(vector<vector<int>>& arr, vector<dataset>& fishes) {
	auto& shark = fishes[0];
	vector<dataset> new_loc;
	int ny, nx;
	for (int i = 1; i < 4; ++i) {
		ny = shark.y + (dy[shark.direc] * i); nx = shark.x + (dx[shark.direc] * i);
		
		if (ny < 0 || ny >= length || nx < 0 || nx >= length) break;
		if (arr[ny][nx] != 0) {
			new_loc.push_back({ ny, nx, fishes[arr[ny][nx]].direc});
		}
	}
	return new_loc;
}

// 물고기 이동 함수.
vector<vector<int>> fish_move(vector<vector<int>> arr, vector<dataset>& fishes) {
	int ny, nx;
	for (auto& fish : fishes) {
		if (fish.live == 0) continue;
		// 8 방향 탐색

		for (int i = 0; i < 8; ++i) {
			int cdir = (fish.direc + i) % 8;
			ny = fish.y + dy[cdir]; nx = fish.x + dx[cdir];

			if (ny < 0 || ny >= length || nx < 0 || nx >= length || arr[ny][nx] == SHARK) continue;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = arr[fish.y][fish.x];	//물고기 이동
				arr[fish.y][fish.x] = 0;
				fish.y = ny;
				fish.x = nx;
				fish.direc = cdir;
				break;
			}
			else {
				int oy = fish.y, ox = fish.x;
				fishes[arr[ny][nx]].y = fish.y;
				fishes[arr[ny][nx]].x = fish.x;
				fish.direc = cdir;
				fish.y = ny;
				fish.x = nx;
				int temp = arr[oy][ox];
				arr[oy][ox] = arr[fish.y][fish.x];
				arr[fish.y][fish.x] = temp;
				break;
			}
		}
	}
	return arr;
}


// 재귀적으로 탐색
void dfs(vector<vector<int>> arr, vector<dataset> fishes, int val) {
	// 물고기 이동.
	vector<dataset> moved_fishes = fishes;
	vector<vector<int>> moved_arr = fish_move(arr, moved_fishes);
	// 이동 가능한 위치 판별.
	
	vector<dataset> canMove = find(moved_arr, moved_fishes);
	// 이동가능한 위치가 없으면 재귀 종료 후 결과 비교.
	if (canMove.empty() == true) {
		if (result < val) {
			result = val;
		}
		return;
	}
	// 이동 가능 위치 있으면 재귀적으로 탐색.
	for (auto& loc : canMove) {
		vector<vector<int>> new_arr = moved_arr;
		vector<dataset> new_fishes = moved_fishes;
		int new_val = moved_arr[loc.y][loc.x];            // 물고기 번호 저장
		new_fishes[new_val].live = 0;                // 기존에 있던 물고기 죽이기
		new_arr[new_fishes[0].y][new_fishes[0].x] = 0;        // 기존 상어 자리 0으로 초기화
		new_arr[loc.y][loc.x] = SHARK;                // 이동할 자리로 상어 채우기
		new_fishes[0].y = loc.y;                    // 상어 y 갱신
		new_fishes[0].x = loc.x;                    // 상어 x 갱신
		new_fishes[0].direc = loc.direc;
		
		dfs(new_arr, new_fishes, val + new_val);    // 재귀적 탐색.
	}
}




int main()
{
	vector<vector<int>> arr(4, vector<int>(4));
	vector<dataset> fishes(17);
	int n, d, val;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cin >> n >> d;
			arr[i][j] = n;
			fishes[n].y = i;
			fishes[n].x = j;
			fishes[n].direc = d - 1;
		}
	}
	// 0, 0 좌표 물고기 삭제.
	fishes[arr[0][0]].live = 0;
	val = arr[0][0];

	// 상어 저장
	fishes[0].direc = fishes[arr[0][0]].direc;
	arr[0][0] = SHARK;
	fishes[0].y = 0;
	fishes[0].x = 0;
	fishes[0].live = 0;
	dfs(arr, fishes, val);

	cout << result << '\n';
	return 0;
}