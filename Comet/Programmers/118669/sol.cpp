#include <string>
#include <vector>
#include <unordered_set>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

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
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	vector<int> answer;
	unordered_set<int> gate;
	unordered_set<int> summit;
	vector<vector<dataset>> graph(n + 1);
	priority_queue<dataset, vector<dataset>, compare> que;
	vector<int> dist(n + 1, INT_MAX);
	sort(summits.begin(), summits.end());
	// 데이터 log(1) 에 찾도록 set에 저장
	for (auto& num : gates) {
		gate.insert(num);
		que.push({ num, 0 });
		dist[num] = 0;
	}
	for (auto& num : summits) {
		summit.insert(num);
	}
	// 그래프 형태로 변경.
	for (auto& info : paths) {
		graph[info[0]].push_back({ info[1], info[2] });
		graph[info[1]].push_back({ info[0], info[2] });
	}
	// 다익스트라 구현
	dataset cur;

		
		

    while (!que.empty())
    {
        cur = que.top(); que.pop();
        if (cur.len > dist[cur.node]) continue;
        for (auto& datas : graph[cur.node]) {
            if (gate.find(datas.node) != gate.end()) continue;

            int new_val = max(datas.len, cur.len);
            if (new_val >= dist[datas.node]) continue;
            dist[datas.node] = new_val;

            if (summit.find(datas.node) != summit.end()) continue;
            que.push({ datas.node, new_val });
        }
    }

	
	int min_idx = 0, min_val = INT_MAX;

	for (auto& num : summits) {
		if (dist[num] < min_val) {
			min_idx = num;
			min_val = dist[num];
		}
	}
	answer = { min_idx, min_val };

	return answer;
}