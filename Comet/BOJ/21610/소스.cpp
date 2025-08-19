using namespace std;
#include <iostream>
#include <vector>
#include <set>
struct yx
{
	int y, x;
	bool operator<(const yx& b) const {
		if (y == b.y) {
			return x < b.x;
		}
		return y < b.y;
	}
};
int length, moves;
vector<vector<int>> arr;
set<yx> clouds;
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

void cloud_move(int dir, int num) {
	set<yx> newClouds;
	for (auto& cloud : clouds) {
		int ny = cloud.y + dy[dir] * num;
		int nx = cloud.x + dx[dir] * num;
		ny = ny % length;
		nx = nx % length;
		if (ny < 0) {
			ny += length;
		}
		if (nx < 0) {
			nx += length;
		}
		newClouds.insert({ ny, nx });
	}
	swap(clouds, newClouds);
}

void rain() {
	for (auto& cloud : clouds) {
		arr[cloud.y][cloud.x] += 1;
	}
}

void copy_water() { 
	int ny, nx;
	for (auto& cloud : clouds) {
				
		for (int k = 1; k < 8; k += 2) {
			ny = cloud.y + dy[k]; nx = cloud.x + dx[k];
			if (ny < 0 || ny >= length || nx < 0 || nx >= length || arr[ny][nx] < 1) continue;
			arr[cloud.y][cloud.x] += 1;
		}

	}
}

void create_cloud() {
	set<yx> newClouds;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (clouds.find({ i, j }) != clouds.end()) continue;
			if (arr[i][j] < 2) continue;
			newClouds.insert({ i, j });
			arr[i][j] -= 2;
		}
	}
	swap(clouds, newClouds);
}


int main()
{
	cin >> length >> moves;
	arr.resize(length, vector<int>(length));
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cin >> arr[i][j];
		}
	}
	int dir, num;
	clouds.insert({ length - 1, 0 });
	clouds.insert({ length - 1, 1 });
	clouds.insert({ length - 2, 0 });
	clouds.insert({ length - 2, 1 });
	for (int m = 0; m < moves; ++m) {
		cin >> dir >> num;
		--dir;
		cloud_move(dir, num);
		rain();

		copy_water();
		create_cloud();
	}
	int result = 0;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			result += arr[i][j];
		}
	}
	cout << result << '\n';
	return 0;
}