#include <iostream>
using namespace std;
#include <vector>



int result = 0;
void dfs(vector<bool> row, vector<bool> col, vector<bool> ltor, vector<bool> rtol, int cnt, int num) {
	if (cnt == num) {
		result++;
		return;
	}

	for (int i = 0; i < num; i++) {

		if (!row[cnt] && !col[i] && !ltor[i + cnt] && !rtol[num - 1 - (cnt - i)]) {
			row[cnt] = 1; col[i] = 1; ltor[i + cnt] = 1; rtol[num - 1 - (cnt - i)] = 1;
			dfs(row, col, ltor, rtol, cnt + 1, num);
			row[cnt] = 0; col[i] = 0; ltor[i + cnt] = 0; rtol[num - 1 - (cnt - i)] = 0;
		}
	}
	return;
}

void solve() {
	result = 0;
	int num; cin >> num;
	vector<bool> row(num, 0);
	vector<bool> col(num, 0);
	vector<bool> ltor(num + num - 1, 0);
	vector<bool> rtol(num + num - 1, 0);

	dfs(row, col, ltor, rtol, 0, num);
	cout << result;
	return;
}

int main() {
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cout << '#' << tc << ' ';
		solve();
		cout << '\n';
	}
	return 0;
}