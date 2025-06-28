#include <iostream>
#include <vector>
#include <deque>
using namespace std;

char cmd[4] = { 'D', 'S', 'L', 'R' };
vector<int> func(int cur) {
	int D, S, L, R;
	D = (cur * 2) % 10000;
	S = ((cur - 1) + 10000) % 10000;

	int d1 = cur / 1000;
	int d2 = (cur / 100) % 10;
	int d3 = (cur / 10) % 10;
	int d4 = cur % 10;
	L = (((((d2 * 10) + d3) * 10) + d4) * 10) + d1;
	R = (((((d4 * 10) + d1) * 10) + d2) * 10) + d3;
	vector<int> res = { D, S, L, R };
	return res;
}

string solve() {
	int A, B, cur;
	cin >> A >> B;

	//cout << A << " / " << B << "\n";
	// A에서 B로 가기 위한 명령어 혹은 B에서 A로 가기 위한 명령어의 역순
	string visited[10009] = { "" };
	deque<int> dq;
	dq.push_back(A);
	while (!dq.empty()) {
		cur = dq.front(); dq.pop_front();
		//cout << "현재 값" << cur.val << " / " << cur.cmd << "\n";
		vector<int> arr = func(cur);
		int idx = -1;
		for (const auto& nxt : arr) {
			//cout << nxt.val << " " << nxt.cmd << "\n";
			idx++;
			if (visited[nxt] != "" || nxt == A) continue;
			if (nxt == B) return visited[cur] + cmd[idx];
			dq.push_back(nxt);
			visited[nxt] = visited[cur] + cmd[idx];
		}
	}
	return "";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cout << solve() << "\n";
	}
	return 0;
}