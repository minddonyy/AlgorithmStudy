using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
struct dataset
{
	int loc, time;
};
struct compare {
	bool operator ()(const dataset& a, const dataset& b) {
		return a.time > b.time;
	}
};
vector<int> visited(100001, INT_MAX);
int main()
{
	int start, end, result = 0;
	cin >> start >> end;
	
	priority_queue<dataset, vector<dataset>, compare> que;
	que.push({ start, 0 });
	visited[start] = 0;
	dataset cur;
	while (!que.empty())
	{
		cur = que.top(); que.pop();
		if (cur.loc == end) {
			result = cur.time;
			break;
		}
		if (cur.time > visited[cur.loc]) continue;

		if ((cur.loc + 1 <= 100000) && (cur.time + 1 < visited[cur.loc + 1])) {
			que.push({ cur.loc + 1 , cur.time + 1 });
			visited[cur.loc + 1] = cur.time + 1;
		}
		if ((cur.loc - 1 >= 0) && (cur.time - 1 < visited[cur.loc - 1])) {
			que.push({ cur.loc - 1 , cur.time + 1 });
			visited[cur.loc - 1] = cur.time + 1;
		}
		if ((cur.loc != 0) && (cur.loc * 2 <= 100000) && (cur.time < visited[cur.loc * 2])) {
			que.push({ cur.loc * 2 , cur.time });
			visited[cur.loc * 2] = cur.time;
		}
	}
	cout << result << '\n';
	return 0;
}