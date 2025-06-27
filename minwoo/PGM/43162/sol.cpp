#include <string>
#include <vector>
#include <deque>

using namespace std;

void bfs(vector<vector<int>>& comp, vector<bool>& visited, int stv, int n) {
    deque<int> dq;
    dq.push_back(stv);
    visited[stv] = true;
    while (!dq.empty()) {
        int vtx = dq.front(); dq.pop_front();
        for (int adj = 0; adj < n; adj++) {
            if (visited[adj] || vtx == adj || comp[vtx][adj] == 0) continue;
            dq.push_back(adj);
            visited[adj] = true;
        }
    }
}


int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n);
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        bfs(computers, visited, i, n);
        answer++;
    }
    return answer;
}