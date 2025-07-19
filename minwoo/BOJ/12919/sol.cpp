#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/* 
	두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임
	- 문자열 뒤에 A를 추가
	- 문자열 뒤에 B를 추가하고 문자열을 뒤집는다.
*/

int len_s, len_t;
string S, T;
bool ans = 0;

void dfs(int len, string& res) {
	if (len == len_s) {
		if (res == S) ans = true;
		return;
	}
	// 뒤에가 a인데 앞에 b일 확률이 있음
	// 이 경우는 두가지 모두 확인할 필요가 있음
	if (res[len - 1] == 'A') {
		res.pop_back();
		dfs(len - 1, res);
		res.push_back('A');
	}
	if (res[0] == 'B') {
		// b를 추가하고 뒤집기
		// 뒤집고 b를 제거하기
		string temp;
		for (int i = len - 1; i > 0; --i) temp.push_back(res[i]);
		dfs(len - 1, temp);
	}
	return;
}

void solve() {
	cin >> S >> T;
	len_s = S.size();
	len_t = T.size();
	dfs(len_t, T);
	cout << ans << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	solve();
	return 0;
}