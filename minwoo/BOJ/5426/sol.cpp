#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void solve() {
	string input;
	cin >> input;
	int n = sqrt(input.size());
	for (int i = n-1; i > -1; i--)
		for (int j = 0; j < n; j++) {
			int idx = (n * j) + i;
			cout << input[idx];
		}
	cout << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	int tt;
	cin >> tt;
	for (int t = 0; t < tt; t++) {
		solve();
	}
	return 0;
}