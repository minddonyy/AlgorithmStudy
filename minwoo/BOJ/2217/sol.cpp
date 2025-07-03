#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

void solve() {
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	// 중량이 w인 물체를 들어올릴 때, 각각의 로프에는 모두 고르게 
	// w/k만큼의 중량이 걸리게 된다. 
	// 이 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해야 함

	int sum = 0;
	int res = 0;
	for (int i = 0; i < N; i++) {
		int cal = v[i] * (i+1);
		/*cout << cal << "\n";*/
		if (res < cal) res = cal;
	}
	//cout << "답: " <<  res << "\n";
	cout << res << "\n";
	return;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	solve();
	return 0;
}