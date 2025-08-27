using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int a, b; cin >> a >> b;
	bool arr[1000001] = { 0 };
	
	arr[0] = 0;
	arr[1] = 0;
	for (int i = 2; i <= b; ++i) {
		arr[i] = 1;
	}
	for (int i = 2; i <= b; ++i) {
		if (!arr[i]) continue;
		for (int j = i + i; j <= b; j += i) {
			arr[j] = 0;
		}
	}
	for (int i = a; i <= b; ++i) {
		if (arr[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}