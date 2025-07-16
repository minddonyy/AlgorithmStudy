import sys
sys.stdin = open('input.txt', 'r')

from collections import deque

dxs = [0, 0, -1, 1]
dys = [1, -1, 0, 0]

N = int(input())
game_map = [list(map(str, input().strip())) for _ in range(2)]
visited = [[0] * N for _ in range(2)]

white = 0
for x in range(2):
    for y in range(N):
        if game_map[x][y] == '.':
            white += 1



queue = deque()
for i in range(2):
    if game_map[i][0] == '.':
        queue.append((i, 0, 1))
        visited[i][0] = 1

min_cnt = 9999999999

while queue:
    x, y, cnt = queue.popleft()

    if y == N-1:
        min_cnt = min(min_cnt, cnt)
        continue

    for dx, dy in zip(dxs, dys):
        nx = dx + x
        ny = dy + y

        if 0 <= nx < 2 and 0 <= ny < N:
            if visited[nx][ny] != 1 and game_map[nx][ny] == '.':
                queue.append((nx, ny, cnt+1))
                visited[nx][ny] = 1


print(white - min_cnt)