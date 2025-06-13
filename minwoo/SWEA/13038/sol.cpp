#include <iostream>
#include <string>
using namespace std;

int TC;
const int DATE = 7;

int run(int n, char arr[], int idx) {
	int d = 0, count = 0;
	// 날짜 시작
	while (n > count) {
		if (arr[idx] == '1') count++;

		// 요일 변경
		idx = (idx + 1) % DATE;
		d++;
	}
	return d;
}

int main() {
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	cin >> TC;
	// 교환학생들을 위한 수업은 특정 요일에만 진행된다.
	// 7개의 정수로 표현(a1, a2, ..., a7)
	// 일요일에 교환학생을 위한 수업이 열리면 a1 = 1, 아니면 0
	// 월요일에 교환학생을 위한 수업이 열리면 a2 = 1 아니면 0 ...
	// 토요일은 a7

	// 교환학생으로 n일동안 수업을 들으려고 한다.
	// 목표를 이루기 위해 대학교에 지내야 하는 최소 일수
	
	for (int t = 1; t <= TC; t++) {
		int n;
		char arr[DATE];
		cin >> n;
		for (int i = 0; i < DATE; i++) cin >> arr[i];

		int result = 1e9;
		// 1. 가장 먼저 열리는 수업의 idx를 잡고
		// 2. 그때부터 while문으로 n == cnt가 된다면 종료
		for (int i = 0; i < DATE; i++) {
			if (arr[i] == '1') {
				int callback = run(n, arr, i);
				result = (result < callback) ? result : callback;
			}
		}
		cout << "#" << t << " " << result << "\n";
	}
}