using namespace std;
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iomanip>
const int BLANK = -99;
int length, color_num, result = 0;
vector<vector<int>> arr;
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };
// 디버깅용 프린트 함수
void print() {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cout << setw(3)<<arr[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

struct yx
{
	int y, x, num;
};
bool compare(const yx& a, const yx& b) {
	if (a.num == b.num) {
		if (a.y == b.y) {
			return a.x < b.x;
		}
		else {
			return a.y < b.y;
		}
	}
	else {
		return a.num > b.num;
	}
}
bool proirity(vector<yx>& ret, vector<yx>& remove, int& rainbow_cnt, int& rain) {
	if (ret.size() < remove.size()) {
		return 1;
	}
	else if (ret.size() > remove.size()) {
		return 0;
	}

	if (rainbow_cnt < rain) {
		return 1;
	}
	else if (rainbow_cnt > rain) {
		return 0;
	}
	sort(ret.begin(), ret.end(), compare);
	sort(remove.begin(), remove.end(), compare);
	if (ret[0].y == remove[0].y) {
		return ret[0].x < remove[0].x;
	}
	else {
		return ret[0].y < remove[0].y;
	}

}
vector<yx> find() {
	//               ߺ  Ž          ϴ   ޸ ...
	vector<yx> rainbow;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (arr[i][j] == 0) {
				rainbow.push_back({ i, j });
			}
		}
	}



	vector<vector<bool>> visited(length, vector<bool>(length, 0));
	vector<yx> ret;
	vector<yx> remove;
	deque<yx> que;
	yx cur;
	int memo, ny, nx, rainbow_cnt = 0;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			if (arr[i][j] <= 0 || visited[i][j] == 1) continue;
			//bfs
			memo = arr[i][j];
			que.clear(); remove.clear();
			int rain = 0;
			visited[i][j] = 1;
			que.push_back({ i, j, arr[i][j] });
			remove.push_back({ i, j, arr[i][j] });
			while (!que.empty())
			{
				cur = que.front(); que.pop_front();
				for (int k = 0; k < 4; ++k) {
					ny = cur.y + dy[k]; nx = cur.x + dx[k];
					if (ny < 0 || ny >= length || nx < 0 || nx >= length || visited[ny][nx] == 1) continue;
					if (arr[ny][nx] == 0 || arr[ny][nx] == memo) {
						if (arr[ny][nx] == 0) rain++;
						visited[ny][nx] = 1;
						que.push_back({ ny, nx, arr[ny][nx] });
						remove.push_back({ ny, nx, arr[ny][nx] });
					}
				}
			}
			// bfs          
			if (proirity(ret, remove, rainbow_cnt, rain) == 1) {
				swap(ret, remove);
				swap(rainbow_cnt, rain);
			}
			//  ߺ Ž       ؾ  ϴ                湮ó    ʱ ȭ.
			for (auto& dat : rainbow) {
				visited[dat.y][dat.x] = 0;
			}
		}
	}
	return ret;
}

void remove(vector<yx> remove) {
	result += remove.size() * remove.size();
	for (auto& rem : remove) {
		arr[rem.y][rem.x] = BLANK;
	}
	
}

void gravity() {
	for (int i = length - 1; i >= 0; --i) {
		for (int j = length - 1; j >= 0; --j) {
			if (arr[i][j] < 0) continue;
			int ni = i;
			for (int k = 0; k < length; ++k) {
				++ni;
				if (ni >= length || arr[ni][j] != BLANK) {
					int temp = arr[i][j];
					arr[i][j] = BLANK;
					arr[ni - 1][j] = temp;
					break;
				}
			}
		}
	}
}

void rotate() {
	vector<vector<int>> newArr(length, vector<int>(length));

	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			newArr[i][j] = arr[j][length - i - 1];
		}
	}
	swap(arr, newArr);
}

int main()
{
	cin >> length >> color_num;
	arr.resize(length, vector<int>(length));
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length; ++j) {
			cin >> arr[i][j];
		}
	}

	while (true)
	{
		// 1. ũ Ⱑ      ū      ׷    ã ´ .  ׷         ׷                  Ե                                   ׷ ,  ׷      ϵ                                 ū     ,     ͵         ̸            ū      ã ´ .
		vector<yx> ret = find();
		if (ret.size() <= 1) {
			break;
		}
		// 2. 1     ã        ׷                   Ѵ .      ׷쿡    Ե             B           , B2     ȹ   Ѵ .
		remove(ret);
		//cout << result << endl;
		//print();
		// 3.    ڿ   ߷     ۿ  Ѵ .                 ڸ      .
		gravity();
		//print();
		// 4.    ڰ  90    ݽð           ȸ   Ѵ .
		rotate();
		//print();
		// 5.  ٽ     ڿ   ߷     ۿ  Ѵ .
		gravity();
		//print();
	}


	cout << result << '\n';
	return 0;
}