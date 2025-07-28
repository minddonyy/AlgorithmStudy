#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int left = 1;
	int right = 0;
	int range = w * 2 + 1;
	for (auto& station : stations) {
		
		left = station - w;
		cout << answer << ' ' << left << ' ' << right << endl;
		if (left <= right + 1) {
			right = station + w;
			continue;
		}
		int diff = left - right - 1;
		answer += diff / range;
		if (diff % range != 0) {
			answer += 1;
		}
		right = station + w;
	}
	cout << answer << ' ' << left << ' ' << right << endl;
	int diff = n - right;
	if (right < n) {
		answer += diff / range;
		if (diff % range != 0) {
			answer += 1;
		}
	}
	

	// [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
	cout << answer << endl;
	return answer;
}

int main() {
	solution(13, { 3, 7, 11 }, 1);
	return 0;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13