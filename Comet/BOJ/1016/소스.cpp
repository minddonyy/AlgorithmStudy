using namespace std;
#include <iostream>
#include <vector>
#include <unordered_map>
int main()
{
	long long start, end;
	cin >> start >> end;
	unordered_map<long long, bool> can;
	for (long long i = 2; i <= end; ++i) {
		long long sq = i * i;
		if (sq > end) break;

		long long startpoint = start / sq;
		if (start % sq != 0) startpoint += 1;
		startpoint *= sq;

		for (long long j = startpoint; j <= end; j += sq) {
			can[j] = 1;
		}
	}
	long long result = 0;
	for (long long i = start; i <= end; ++i) {
		if (can[i] == 0) {
			++result;
		}
	}
	cout << result << '\n';
	return 0;
}