#include <string>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> computers, vector<bool>& visited, int num, int n){
    queue<int> que; que.push(num); int cur; visited[num] = 1;
    while (!que.empty()){
        cur = que.front(); que.pop();
        for (int i = 0; i < n; i++){
            if (computers[cur][i] && !visited[i]){
                visited[i] = 1;
                que.push(i);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++){
        if (visited[i] == 0){
            bfs(computers, visited, i, n);
            answer++;
        }
    }
    return answer;
}