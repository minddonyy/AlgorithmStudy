#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> map(n, vector<int>(m, 0));
    for (int i = 0; i < puddles.size(); i++){
        map[puddles[i][1] - 1][puddles[i][0] - 1] = -1;
    }
    map[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == -1) continue;
            if (i - 1 >= 0 && map[i - 1][j] >= 0) map[i][j] += map[i-1][j];
            if (j - 1 >= 0 && map[i][j - 1] >= 0) map[i][j] += map[i][j - 1];
            map[i][j] %= 1000000007;
        }
    }
    
    answer = map[n - 1][m - 1];
    return answer;
}