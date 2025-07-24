using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
struct dataset
{
	int start = 0, end = 0;

};
int num;
int result = -1;
int main() {
	cin >> num;
	vector<dataset> works(num + 1);

	int t, n, w;
	for (int i = 1; i <= num; ++i) {
		cin >> t >> n;
		int min_time = 0;

		for (int j = 0; j < n; ++j) {
			cin >> w;
			min_time = max(works[w].end, min_time);
		}
		works[i].start = min_time;
		works[i].end = min_time + t;
		result = max(works[i].end, result);
	}
	cout << result << '\n';
	return 0;
}