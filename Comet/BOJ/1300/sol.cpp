using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
	long long length, idx; cin >> length >> idx;
	long long left = 1, right = length * length, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		long long ans = 0;
		for (int i = 1; i <= length; ++i) {
			ans += min(length, mid / i);
		}
		if (ans < idx) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left << '\n';
	return 0;
}