using namespace std;
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
struct dataset
{
	int node, len;
};
struct compare
{
	bool operator ()(const dataset& a, const dataset& b) {
		return a.len > b.len;
	}
};
int num, Lnum, Pnum;

void dijk(vector<vector<dataset>>& graph, vector<int>& dist) {
	priority_queue<dataset,  vector<dataset>, compare> que;
	dist[Pnum] = 0;
	que.push({ Pnum, 0 });
	dataset cur;
	while (!que.empty())
	{
		cur = que.top(); que.pop();
		if (cur.len > dist[cur.node]) continue;
		for (auto& road : graph[cur.node]) {
			int nextlen = cur.len + road.len;
			if (nextlen > dist[road.node]) continue;
			dist[road.node] = nextlen;
			que.push({ road.node, nextlen });
		}
	}

}
int main() {
	cin >> num >> Lnum >> Pnum;
	vector<vector<dataset>> graph(num + 1);
	vector<vector<dataset>> Rgraph(num + 1);
	int a, b, l;

	for (int i = 0; i < Lnum; ++i) {
		cin >> a >> b >> l;
		graph[a].push_back({ b, l });
		Rgraph[b].push_back({ a, l });
	}
	vector<int> dist1(num + 1, INT_MAX);
	vector<int> dist2(num + 1, INT_MAX);
	dijk(graph, dist1);
	dijk(Rgraph, dist2);
	int max_val = -1, val;
	for (int i = 1; i <= num; ++i) {
		val = dist1[i] + dist2[i];
		if (val > max_val) {
			max_val = val;
		}
	}
	cout << max_val << '\n';
}
