#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
크기가 n x n인 배열 A
배열에 들어있는 수 A[i][j] = i x j이다\
이 수를 일차원 배열 b에 넣으면 b의 크기는 N x N이 된다.
B를 오름차순 정렬했을 때, B[k]
배열 A와 B의 인덱스는 1부터 시작
min(n, m/i)
m은 1 ~ n x n 사이 값 중 중앙값
i는 
*/
long long n, k;

void solve() {
	cin >> n >> k;

	long long low = 1, high = n * n;
	long long res = high;
	while (low <= high) {
		long long val = 0;
		long long mid = (low + high) / 2;
		for (int i = 1; i <= n; i++) {
			val += min(n, mid / i);
		}
		if (val >= k) {
			high = mid - 1;
			res = min(res, mid);
		}
		else
			low = mid + 1;
	}
	cout << res << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
	solve();
	return 0;
}