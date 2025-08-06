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
// �̵� ������ġ ��ȯ �Լ�.
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

// ����� �̵� �Լ�.
vector<vector<int>> fish_move(vector<vector<int>> arr, vector<dataset>& fishes) {
	int ny, nx;
	for (auto& fish : fishes) {
		if (fish.live == 0) continue;
		// 8 ���� Ž��

		for (int i = 0; i < 8; ++i) {
			int cdir = (fish.direc + i) % 8;
			ny = fish.y + dy[cdir]; nx = fish.x + dx[cdir];

			if (ny < 0 || ny >= length || nx < 0 || nx >= length || arr[ny][nx] == SHARK) continue;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = arr[fish.y][fish.x];	//����� �̵�
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


// ��������� Ž��
void dfs(vector<vector<int>> arr, vector<dataset> fishes, int val) {
	// ����� �̵�.
	vector<dataset> moved_fishes = fishes;
	vector<vector<int>> moved_arr = fish_move(arr, moved_fishes);
	// �̵� ������ ��ġ �Ǻ�.
	
	vector<dataset> canMove = find(moved_arr, moved_fishes);
	// �̵������� ��ġ�� ������ ��� ���� �� ��� ��.
	if (canMove.empty() == true) {
		if (result < val) {
			result = val;
		}
		return;
	}
	// �̵� ���� ��ġ ������ ��������� Ž��.
	for (auto& loc : canMove) {
		vector<vector<int>> new_arr = moved_arr;
		vector<dataset> new_fishes = moved_fishes;
		int new_val = moved_arr[loc.y][loc.x];            // ����� ��ȣ ����
		new_fishes[new_val].live = 0;                // ������ �ִ� ����� ���̱�
		new_arr[new_fishes[0].y][new_fishes[0].x] = 0;        // ���� ��� �ڸ� 0���� �ʱ�ȭ
		new_arr[loc.y][loc.x] = SHARK;                // �̵��� �ڸ��� ��� ä���
		new_fishes[0].y = loc.y;                    // ��� y ����
		new_fishes[0].x = loc.x;                    // ��� x ����
		new_fishes[0].direc = loc.direc;
		
		dfs(new_arr, new_fishes, val + new_val);    // ����� Ž��.
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
	// 0, 0 ��ǥ ����� ����.
	fishes[arr[0][0]].live = 0;
	val = arr[0][0];

	// ��� ����
	fishes[0].direc = fishes[arr[0][0]].direc;
	arr[0][0] = SHARK;
	fishes[0].y = 0;
	fishes[0].x = 0;
	fishes[0].live = 0;
	dfs(arr, fishes, val);

	cout << result << '\n';
	return 0;
}