import sys
sys.stdin = open('input.txt', 'r')

N, M = map(int, input().split())
x, y, d = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(N)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

visited = [[0]*M for _ in range(N)]
result = 0

while True:
    if visited[x][y] == 0:
        visited[x][y] = 1
        result += 1

    moved = False
    for _ in range(4):
        d = (d + 3) % 4
        nx = x + dx[d]
        ny = y + dy[d]

        if 0 <= nx < N and 0 <= ny < M and room[nx][ny] == 0 and visited[nx][ny] == 0:
            x, y = nx, ny
            moved = True
            break

    if moved:
        continue

    back = (d + 2) % 4
    bx = x + dx[back]
    by = y + dy[back]

    if 0 <= bx < N and 0 <= by < M and room[bx][by] == 0:
        x, y = bx, by
    else:
        break

print(result)
