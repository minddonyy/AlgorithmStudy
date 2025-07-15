#include <iostream>
#include <vector>
using namespace std;

int n, ans = 0;
vector<int> a;
vector<int> b;

void check_array() {
	for (int i = 0; i < n; i++)
		if (a[i] != b[i]) return;
    ans = 1;
	return;
}

void insertion_sort() {
	check_array();
	for (int i = 1; i < n; i++) {
		int loc = i - 1;
		int num = a[i];

		while (0 <= loc and num < a[loc]) {
			a[loc + 1] = a[loc];
			check_array();
            loc--;
		}
		if (loc + 1 != i) {
			a[loc + 1] = num;
			check_array();
		}
	}
}

void solve() {
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	insertion_sort();
	cout << ans << "\n";
	return;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solve();
	return 0;
}