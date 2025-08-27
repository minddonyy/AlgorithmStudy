using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
// 구조체 선언
struct sharkdata
{
	int num = 0, y, x, dir;
	int priority[4][4] = { 0 };
	bool is_out = 0;
};
struct smelldata 
{	
	vector<int> nums;
	int smellnum = 0;
	int smell = 0;
};
struct next_movedata
{
	int num, ny, nx, ndir;
};
// 배열 및 변수 선언.
vector<vector<smelldata>> arr;
vector<sharkdata> sharks;
int length, shark_num, smell_time;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int shark_cnt;
vector<next_movedata> select_move() {
	vector<next_movedata> next_move;
	int ny, nx;
	for (auto& shark : sharks) {
		if (shark.is_out == 1) continue;	//없는 상어는 건너 뜀.
		bool flag = 0;						
		for (int& d : shark.priority[shark.dir]) {
			ny = shark.y + dy[d]; nx = shark.x + dx[d];
			if (ny < 0 || ny >= length || nx < 0 || nx >= length) continue;
			if (arr[ny][nx].smell == 0) {
				flag = 1;
				next_move.push_back({ shark.num, ny, nx, d });
				break;
			}
		}
		if (flag == 1) continue;
		for (int& d : shark.priority[shark.dir]) {
			ny = shark.y + dy[d]; nx = shark.x + dx[d];
			if (ny < 0 || ny >= length || nx < 0 || nx >= length) continue;
			if (arr[ny][nx].smellnum == shark.num) {
				next_move.push_back({ shark.num, ny, nx, d });
				break;
			}
		}
	}

	return next_move;
}


void sharks_move(vector<next_movedata>& next_move) {
	for (auto& move : next_move) {
		auto& shark = sharks[move.num];
		arr[shark.y][shark.x].nums.pop_back();	// 기존 상어 위치에서 상어 번호 제거.
		shark.y = move.ny;						
		shark.x = move.nx;
		shark.dir = move.ndir;
		arr[shark.y][shark.x].nums.push_back(shark.num);
		arr[shark.y][shark.x].smellnum = shark.num;
		arr[shark.y][shark.x].smell = smell_time + 1;
	}
}


void out_and_smell() {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (arr[i][j].smell != 0) {
				arr[i][j].smell -= 1;
			}
			if (arr[i][j].smell == 0) arr[i][j].smellnum = 0;
			if (arr[i][j].nums.size() <= 1) continue;
			sort(arr[i][j].nums.begin(), arr[i][j].nums.end());
			while (arr[i][j].nums.size() > 1)
			{
				int delnum = arr[i][j].nums.back();
				sharks[delnum].is_out = 1;
				arr[i][j].nums.pop_back();
				shark_cnt -= 1;
			}
			arr[i][j].smellnum = arr[i][j].nums[0];
		}
	}
}


int main()
{	
	// 입력 받기 및 배열 사이즈 설정.
	cin >> length >> shark_num >> smell_time;
	arr.resize(length, vector<smelldata>(length));
	sharks.resize(shark_num + 1);
	// 상어 초기 위치 입력 받기.
	int input;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cin >> input;
			if (input != 0) {
				arr[i][j].nums.push_back(input);
				arr[i][j].smellnum = input;
				arr[i][j].smell = smell_time;
				sharks[input].num = input;
				sharks[input].y = i;
				sharks[input].x = j;
			}
		}
	}
	// 초기 상어 방향 입력 받기.
	for (int i = 1; i <= shark_num; ++i) {
		cin >> sharks[i].dir;
		sharks[i].dir -= 1;
	}
	// 상어 우선순위 입력 받기.
	for (int n = 1; n <= shark_num; ++n) {
		auto& shark = sharks[n];
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				cin >> input;
				--input;
				shark.priority[i][j] = input;
			}
		}
	}
	
	// 0번 상어는 없는 상어니 아웃.
	sharks[0].is_out = 1;
	// 시뮬레이션 시작.
	shark_cnt = shark_num;
	int result = 0;
	while (shark_cnt > 1 && result < 1000)
	{	
		// 상어 이동 위치 결정.
		vector<next_movedata> next_move = select_move();
		// 상어 이동.
		sharks_move(next_move);
		// 상어 아웃 및 냄새 감소.
		out_and_smell();
		// 시간 증가.
		++result;
	}
	if (shark_cnt == 1) {
		cout << result << '\n';
	}
	else {
		cout << -1 << '\n';
	}

	
	return 0;
}