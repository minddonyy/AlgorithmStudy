#include <iostream>
#include <string>
#include <vector>
using namespace std;
int N, K;
// N < 1백만
// 시행 횟수는 2N 이하로 출력되야 함
/*
	현재 위치에서 문자 2개를 확인(SU인가 US인가 둘다 아닌가)
	SU인가 -> 1번 실행
	US인가 -> 3번 실행
	둘 다 아닌가 -> 2번 실행 후 재평가
*/

void solve() {
	string grade;
	cin >> N >> grade;

	vector<char> arr;
	string cmd;
	// 뒤에서부터 확인
	for (int i = grade.size() - 1; i > -1; i--) {
		bool flag = 0;	
		if (!arr.empty() && grade[i] == arr.back()) {
			arr.pop_back();
			cmd.push_back('N');
			continue;
		}
		
		if (grade[i] == 'U') {
			cmd.push_back('S');
			arr.push_back('S');
		}
		else {
			cmd.push_back('U');
			arr.push_back('U');
		}
		cmd.push_back('N');
	}

	cout << cmd.size() << "\n" << cmd << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	solve();
	return 0;
}