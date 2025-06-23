import sys
from collections import deque
sys.stdin = open("input.txt", "r")
input = sys.stdin.readline
dxy = (1, 0), (0, 1), (-1, 0), (0, -1)


def bfs(sx, sy, color):
    global A, visited
    dq = deque([(sx, sy)])
    coord = [(sx, sy)]
    visited[sx][sy] = True

    while dq:
        x, y = dq.popleft()
        for dx, dy in dxy:
            nx, ny = x + dx, y + dy
            if nx >= N or nx < 0 or ny >= M or ny < 0: continue
            if visited[nx][ny] or A[nx][ny] != A[sx][sy]: continue
            coord.append((nx, ny))
            dq.append((nx, ny))
            visited[nx][ny] = True
    for x, y in coord:
        A[x][y] = color


N, M = map(int, input().split())
A = [list(input().strip()) for _ in range(N)]
B = [list(input().strip()) for _ in range(N)]
visited = [[False] * M for _ in range(N)]
for i in range(N):
    for j in range(M):
        if visited[i][j] == 1 or A[i][j] == B[i][j]:
            continue
        bfs(i, j, B[i][j])

for i in range(N):
    for j in range(M):
        if A[i][j] != B[i][j]:
            print("NO")
            exit()
print("YES")