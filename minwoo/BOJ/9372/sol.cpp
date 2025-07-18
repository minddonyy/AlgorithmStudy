#include <iostream>
using namespace std;

int t, n, m;
 
void solve() {
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
	}
	cout << n - 1 << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int tt = 0; tt < t; tt++) {
		solve();
	}
	return 0;
}