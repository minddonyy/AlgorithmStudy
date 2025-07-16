#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/* 

두 팀으로 나눠져서 작업을 진행
두 팀 도우 적어도 한명은 포함되야 함
두 팀이 같은 수의 상자를 옮길 필요는 없음

팀 작업 속도 = (해당 팀에 속한 사람들의 작업속도 중 가장 느린 작업속도) x (팀에 속한 사람 수)


*/

long long n, k;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	sort(v.begin(), v.end());

	long long res = 1e18;
	for (int i = 1; i < n; ++i) {
		// a팀 사람 수 = i
		// b팀 사람 수 = n - i
		long long per = (v[0] * i) + (v[i] * (n - i));
		long long temp = (k / per) + (((k % per) > 0) ? 1 : 0);
		res = min(res, temp);
	}
	cout << res << "\n";

	return 0;
}