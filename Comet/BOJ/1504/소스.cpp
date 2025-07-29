using namespace std;
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
int node_num, line_num;
int must[2];
struct lineData
{
	int node, length;
};
struct queData
{
	int node, length;
	int visit;
};
struct compare
{
	bool operator ()(const queData& a, const queData& b) {
		return a.length > b.length;
	}
};

vector<vector<lineData>> graph;
void dijk() {
	vector<vector<int>> dist(node_num + 1, vector<int>(4, INT_MAX));
	dist[1][0] = 0;
	priority_queue<queData, vector<queData>, compare> que;
	if (1 == must[0] ) {
		que.push({ 1, 0, 1 });
	}
	else if (1 == must[1]) {
		que.push({ 1, 0, 2 });
	}
	else {
		que.push({ 1, 0, 0 });
	}
	que.push({ 1, 0, 0 });
	queData cur;
	while (!que.empty())
	{
		cur = que.top(); que.pop();
		if (cur.length > dist[cur.node][cur.visit]) continue;
		for (auto& line : graph[cur.node]) {

			if (line.node == must[0] && (cur.visit & 1) == 0) {
				if (line.length + cur.length > dist[line.node][cur.visit + 1]) continue;
				que.push({ line.node, line.length + cur.length , cur.visit + 1 });
				dist[line.node][cur.visit + 1] = line.length + cur.length;
			}
			else if (line.node == must[1] && (cur.visit & 2) == 0) {
				if (line.length + cur.length > dist[line.node][cur.visit + 2]) continue;
				que.push({ line.node, line.length + cur.length , cur.visit + 2 });
				dist[line.node][cur.visit + 2] = line.length + cur.length;
			}
			else {
				if (line.length + cur.length > dist[line.node][cur.visit]) continue;
				que.push({ line.node, line.length + cur.length , cur.visit });
				dist[line.node][cur.visit] = line.length + cur.length;
			}

		}
	}
	if (dist[node_num][3] == INT_MAX) {
		cout << -1 << '\n';
	}
	else {
		cout << dist[node_num][3] << '\n';
	}
}

int main() {
	cin >> node_num >> line_num;
	graph.resize(node_num + 1);
	int a, b, l;
	for (int i = 0; i < line_num; ++i) {
		cin >> a >> b >> l;
		graph[a].push_back({ b, l });
		graph[b].push_back({ a, l });
	}
	cin >> must[0] >> must[1];
	dijk();
	return 0;
}