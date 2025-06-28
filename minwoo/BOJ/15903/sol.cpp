#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);

	int N, M;
	priority_queue<long long int, vector<long long int>, greater<long long int>> pq;

	cin >> N >> M;
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}
	for (int i = 0; i < M; i++) {
		long long int x = pq.top(); 
		pq.pop();
		long long int y = pq.top(); 
		pq.pop();
		pq.push(x+y); pq.push(x+y);
	}
	int result = 0;
	while (!pq.empty()) {
		result += pq.top();
		pq.pop();
	}
	cout << result << "\n";
	return 0;
}