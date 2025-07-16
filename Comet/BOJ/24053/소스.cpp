using namespace std;
#include <iostream>
#include <vector>
int num;
vector<int> a;
vector<int> b;
bool find() {
	for (int i = 0; i < num; ++i) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}
int main() {
	cin >> num;
	a.resize(num);
	b.resize(num);
	for (int i = 0; i < num; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < num; ++i) {
		cin >> b[i];
	}

	int loc, cur;
	for (int i = 1; i < num; ++i) {
		loc = i - 1;
		cur = a[i];
		while (loc >= 0)
		{
			if (a[loc] > cur) {
				a[loc + 1] = a[loc];
			}
			else {
				break;
			}
			if (find()) {
				cout << 1 << '\n';
				return 0;
			}
			loc--;
		}
		if (loc + 1 != i) {
			a[loc + 1] = cur;
		}
	}
	cout << 0 << '\n';
	return 0;
}
1000000000
