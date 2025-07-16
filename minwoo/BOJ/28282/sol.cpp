#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

int x, k;
vector<int> l;
vector<int> r;
unordered_map<int, int> um;

void solve() {
	cin >> x >> k;
	l.resize(x);
	r.resize(x);
	for (int i = 0; i < x; i++) cin >> l[i];
	for (int i = 0; i < x; i++) {
		cin >> r[i];
		um[r[i]]++;
	}

	long long ans = 0;
	for (const int num : l) {
		ans += x - um[num];
	}
	cout << ans << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solve();
	return 0;
}