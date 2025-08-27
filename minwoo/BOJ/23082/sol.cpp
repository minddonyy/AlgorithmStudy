#include <iostream>
#include <string>
using namespace std;

string solve(int n) {
	if (n == 0) return "0";

	string res = "";
	while (n != 0) {
		int x = n % 3;
		n /= 3;
		if (x == 2 || x == -1) {
			res = 'T' + res;
			if (x >= 0) n++;
		}
		else if (x == -2 || x == 1) {
			res = '1' + res;
			if (x < 0) n--;
		}
		else {
			res = '0' + res;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	int n;
	cin >> n;
	cout << solve(n) << "\n";

	return 0;
}