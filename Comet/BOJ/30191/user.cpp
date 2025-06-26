//user.cpp
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
struct nodes
{
	int num, limit;
};
struct dfsNodes
{
	int num, done;
};

vector<vector<nodes>> graph;
deque<dfsNodes> dq;
int n;
void init(int N, int K, int sCity[], int eCity[], int mLimit[]) {
	graph.clear();
	n = N;
	graph.resize(N);
	for (int i = 0; i < K; ++i)
	{
		graph[sCity[i]].push_back({ eCity[i], mLimit[i] });
		graph[eCity[i]].push_back({ sCity[i], mLimit[i] });
	}

	return;
}

void add(int sCity, int eCity, int mLimit) {
	graph[sCity].push_back({ eCity, mLimit });
	graph[eCity].push_back({ sCity, mLimit });
	return;
}



bool dfs(int sCity, int eCity, int M, int mStopover[], int mid) {
	dq.clear();
	dq.push_back({ sCity, 0 });
	vector<vector<bool>> visited(n, vector<bool>(8));
	visited[sCity][0] = 1;
	dfsNodes cur;
	int complete;
	if (M == 1) { complete = 1; }
	else if (M == 2) { complete = 3; }
	else { complete = 7; }


	int newDone;
	while (!dq.empty())
	{
		cur = dq.front(); dq.pop_front();

		if (cur.num == eCity && cur.done == complete) return 1;

		for (auto& cnode : graph[cur.num])
		{
			
			if (cnode.limit < mid) continue;
			newDone = cur.done;
			
			for (int i = 0; i < M; ++i)
			{
				if (mStopover[i] == cnode.num)
				{
					newDone |= 1 << i;
					break;
				}
			}
			if (visited[cnode.num][newDone]) continue;
			visited[cnode.num][newDone] = 1;
			dq.push_back({ cnode.num, newDone });
		}
	}
	return 0;
}



int calculate(int sCity, int eCity, int M, int mStopover[]) {
	int left = 0, right = 30000, mid, result = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (dfs(sCity, eCity, M, mStopover, mid))
		{	
			result = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	//cout << sCity << ' ' << eCity << ' ' << result << '\n';
	return result;
}

