#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int num, w_num;
struct dataset
{
	int node_1, node_2, len;
};
struct compare
{
	bool operator ()(const dataset& a, const dataset& b) {
		return a.len > b.len;
	}
};
priority_queue<dataset, vector<dataset>, compare> que;
vector<int> parents;
int find_parents(int n) {
	if (parents[n] == n) {
		return n;
	}
	parents[n] = find_parents(parents[n]);
	return parents[n];
}

void unions(int a, int b) {
	int pa = find_parents(a);
	int pb = find_parents(b);
	if (pa < pb) {
		parents[pb] = pa;
	}
	else {
		parents[pa] = pb;
	}
}







int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> num >> w_num;
	int a, b, l;
	int result = 0;
	for (int i = 0; i <=num; ++i) {
		parents.push_back(i);
	}
	for (int i = 0; i < w_num; ++i) {
		cin >> a >> b >> l;
		que.push({ a, b, l });
	}
	dataset cur;
	for (int i = 1; i < num;) {
		cur = que.top(), que.pop();
		if (find_parents(cur.node_1) == find_parents(cur.node_2)) continue;
		unions(cur.node_1, cur.node_2);
		result += cur.len;
		++i;
		//cout << cur.len << endl;
	}

	cout << result << '\n';
	return 0;
}