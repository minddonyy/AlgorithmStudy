#include <iostream>
#include <string>
using namespace std;
bool endpoint = true;

pair<int, int> get_input() {
	int r = 0, c = 0;
	string input;
	getline(cin, input);
	int n = input.size();
	int digits = 1;
	while (isdigit(input[--n])) {
		c += (input[n] - '0') * digits;
		digits *= 10;
	}
	digits = 1;
	while (isdigit(input[--n])) {
		r += (input[n] - '0') * digits;
		digits *= 10;
	}
	return { r, c };
}

string to_26(int n) {
	string res;
	
	while (n > 0) {
		res = char((--n % 26) + 'A') + res;
		n /= 26;
	}
	return res;
}

void solve() {
	auto [row, col] = get_input();
	if (row == 0 && col == 0) {
		endpoint = false;
		return;
	}

	// A~Z 사이에서
	// 1부터 시작 -> 0부터 시작
	string c = to_26(col);
	cout << c << row << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(& fp, "input.txt", "r", stdin);
	while (endpoint)
		solve();
	return 0;
}