import sys
sys.stdin = open('input.txt', 'r')

def dfs(depth, num):
    if depth == M:
        print(*num)
        return

    for i in range(1, N + 1):
        if not visited[i]:
            visited[i] = 1
            dfs(depth + 1, num + [i])
            visited[i] = 0

N, M = map(int, input().split())
visited = [0] * (N + 1)

dfs(0, [])
