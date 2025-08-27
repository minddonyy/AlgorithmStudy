#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Data {
	int i;
	bool operator<(const Data& other) const {
		return i > other.i;
	}
};

void solve() {
	int n;
	cin >> n;

	vector<Data> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].i;
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) cout << v[i].i << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}