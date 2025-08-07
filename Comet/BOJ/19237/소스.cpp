using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
// ����ü ����
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
// �迭 �� ���� ����.
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
		if (shark.is_out == 1) continue;	//���� ���� �ǳ� ��.
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
		arr[shark.y][shark.x].nums.pop_back();	// ���� ��� ��ġ���� ��� ��ȣ ����.
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
	// �Է� �ޱ� �� �迭 ������ ����.
	cin >> length >> shark_num >> smell_time;
	arr.resize(length, vector<smelldata>(length));
	sharks.resize(shark_num + 1);
	// ��� �ʱ� ��ġ �Է� �ޱ�.
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
	// �ʱ� ��� ���� �Է� �ޱ�.
	for (int i = 1; i <= shark_num; ++i) {
		cin >> sharks[i].dir;
		sharks[i].dir -= 1;
	}
	// ��� �켱���� �Է� �ޱ�.
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
	
	// 0�� ���� ���� ���� �ƿ�.
	sharks[0].is_out = 1;
	// �ùķ��̼� ����.
	shark_cnt = shark_num;
	int result = 0;
	while (shark_cnt > 1 && result < 1000)
	{	
		// ��� �̵� ��ġ ����.
		vector<next_movedata> next_move = select_move();
		// ��� �̵�.
		sharks_move(next_move);
		// ��� �ƿ� �� ���� ����.
		out_and_smell();
		// �ð� ����.
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