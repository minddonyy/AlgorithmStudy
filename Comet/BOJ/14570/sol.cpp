using namespace std;
#include <iostream>
#include <vector>
struct nodes
{
	int left, right;
};
vector<nodes> graph;
int dfs(long long tar, int node) {
	if (graph[node].left == -1 && graph[node].right == -1) {
		return node;
	}
	if (graph[node].left == -1) {
		return dfs(tar, graph[node].right);
	}
	if (graph[node].right == -1) {
		return dfs(tar, graph[node].left);
	}
	if (tar % 2 == 1) {
		return dfs((tar / 2) + 1, graph[node].left);
	}
	else {
		return dfs(tar / 2, graph[node].right);
	}
}
int main() {
	int num, U, V; cin >> num;
	long long tar;
	graph.resize(num + 1);
	for (int i = 1; i <= num; i++) {
		cin >> U >> V;
		graph[i].left = U;
		graph[i].right = V;
	}
	cin >> tar;
	cout << dfs(tar, 1) << '\n';


	return 0;
}