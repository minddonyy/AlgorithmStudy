import sys
sys.stdin = open("input.txt", "r")
sys.setrecursionlimit(10**6)
dxy = (1, 0), (0, 1), (-1, 0), (0, -1)
input = sys.stdin.readline


def dfs(x, y):
    global dp, grid, end_xy
    if (x, y) == end_xy:
        return 1

    if dp[x][y] != -1:
        return dp[x][y]

    dp[x][y] = 0
    for dx, dy in dxy:
        nx, ny = x + dx, y + dy
        if nx >= M or nx < 0 or ny >= N or ny < 0:
            continue
        if grid[nx][ny] < grid[x][y]:
            dp[x][y] += dfs(nx, ny)
    return dp[x][y]


M, N = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(M)]
dp = [[-1] * N for _ in range(M)]
start_xy = (0, 0)
end_xy = (M-1, N-1)

print(dfs(*start_xy))

# 1. BFS로도 경로를 계산할 수 있다. 하지만 오래 걸릴 뿐
# 그러면 어떤 경로로 이동하기 위해서 지나온 길을 알고 있고, 해당 경로까지 유효하다면, 다시 해당 시점부터 시작하는 것

