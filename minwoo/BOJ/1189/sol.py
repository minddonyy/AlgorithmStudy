import sys
input = sys.stdin.readline
dxy = (0, -1), (-1, 0), (0, 1), (1, 0)


def dfs(depth, x, y):
    global arr, visited, ans, R, C
    if (x, y) == (0, C-1):
        if depth == K: ans += 1
        return
    for dx, dy in dxy:
        nx, ny = x + dx, y + dy
        if nx >= R or nx < 0 or ny >= C or ny < 0: continue
        if visited[nx][ny] or arr[nx][ny] == 'T': continue
        visited[nx][ny] = 1
        dfs(depth + 1, nx, ny)
        visited[nx][ny] = 0


R, C, K = map(int, input().split())
arr = [list(input().strip()) for _ in range(R)]
visited = [[0] * C for _ in range(R)]
ans = 0
visited[R - 1][0] = 1
dfs(1, R - 1, 0)
print(ans)
