import sys

sys.stdin = open('input.txt', 'r')

from collections import deque
dz = [1, -1, 0, 0, 0, 0]
dx = [0, 0, 1, -1, 0, 0]
dy = [0, 0, 0, 0, 1, -1]

def tomatoma():
    last_day = 0
    while queue:
        z, x, y, d = queue.popleft()
        last_day = d
        for n in range(6):
            nz, nx, ny = z + dz[n], x + dx[n], y + dy[n]
            if 0 <= nz < H and 0 <= nx < N and 0 <= ny < M:
                if tomatoes[nz][nx][ny] == 0:
                    tomatoes[nz][nx][ny] = 1
                    queue.append((nz, nx, ny, d + 1))
    return last_day

M, N, H = map(int, input().split())
tomatoes = [[list(map(int, input().split())) for _ in range(N)] for _ in range(H)]

queue = deque()
for z in range(H):
    for x in range(N):
        for y in range(M):
            if tomatoes[z][x][y] == 1:
                queue.append((z, x, y, 0))

day = tomatoma()

for z in range(H):
    for x in range(N):
        for y in range(M):
            if tomatoes[z][x][y] == 0:
                print(-1)
                sys.exit(0)

print(day)
