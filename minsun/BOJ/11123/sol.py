from collections import deque

dxy = [[0,1], [0,-1], [1,0], [-1, 0]]

def find_lamb(start_x, start_y):
    queue = deque()
    queue.append((start_x, start_y))
    visited[start_x][start_y] = 1

    while queue:
        x, y = queue.popleft()

        for dx, dy in dxy:
            nx = dx + x
            ny = dy + y

            if 0 <= nx < h and 0 <= ny < w:
                if visited[nx][ny] != 1 and lamb[nx][ny] != '.':
                    queue.append((nx, ny))
                    visited[nx][ny] = 1


t = int(input())
for tc in range(1, t+1):
    h, w = map(int, input().split())
    visited = [[0] * w for _ in range(h)]
    lamb = [list(input().strip()) for _ in range(h)]

    result = 0
    for i in range(h):
        for j in range(w):
            if lamb[i][j] == '#' and visited[i][j] == 0:
                find_lamb(i, j)
                result += 1

    print(result)

