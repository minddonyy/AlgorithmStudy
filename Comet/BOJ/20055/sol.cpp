#include <iostream>
using namespace std;
#include <vector>
#include <deque>

void drop(deque<vector<int>>& conveyor, int down) {
	conveyor[down][0] = 0;
}

int main() {
	int length, limit; cin >> length >> limit;
	deque<vector<int>> conveyor;
	int input_temp;
	for (int i = 0; i < length * 2; i++) {
		cin >> input_temp;
		conveyor.push_back({ 0, input_temp });
	}
	int up = 0, down = length - 1, is_robot = 0, durability = 1, cnt = 0;
	int sycle = 0;
	vector<int> temp;
	// 내구도 0이 제한 이상이 되면 종료
	while (cnt < limit)
	{
		sycle++;
		// 컨베이어 한칸 이동
		temp = conveyor.back(); conveyor.pop_back();
		conveyor.push_front(temp);
		// 로봇이 내리는곳 도착하면
		if (conveyor[down][is_robot]) drop(conveyor, down);

		//로봇 한칸씩 이동, 내구도 1씩 감소
		for (int i = length - 2; i >= 0; i--) {
			if (conveyor[i][is_robot] && !conveyor[i + 1][is_robot] && conveyor[i + 1][durability] >= 1) {
				conveyor[i][is_robot] = 0;
				conveyor[i + 1][is_robot] = 1;
				conveyor[i + 1][durability]--;
				if (conveyor[i + 1][durability] == 0) cnt++;
			}
		}
		// 로봇이 내리는곳 도착하면
		if (conveyor[down][is_robot]) drop(conveyor, down);
		// 로봇 올리기
		if (conveyor[up][durability] >= 1) {
			conveyor[up][is_robot] = 1;
			conveyor[up][durability]--;
			if (conveyor[up][durability] == 0) cnt++;
		}
		
	}
	cout << sycle << '\n';
	return 0;
}