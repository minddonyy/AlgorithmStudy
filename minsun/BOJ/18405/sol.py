import sys
sys.stdin = open('input.txt', 'r')

from collections import deque

dxs = [-1, 1, 0, 0]
dys = [0, 0, -1, 1]

N, K = map(int, input().split())
virus = [list(map(int, input().split())) for _ in range(N)]
temp = []

S,X,Y = map(int, input().split()) # 초, 행, 열

for i in range(N):
    for j in range(N):
        if virus[i][j] != 0: # 바이러스가 있는 경우
            temp.append((virus[i][j], 0, i, j)) # 바이러스, 시간, 위치


temp.sort() # 낮은 번호 먼저 증식하니ㄲ ㅏ 낮은 것부터
queue = deque(temp)

while queue:
    vi, second, x, y = queue.popleft()

    if second == S: # 시간 끝나면 break
        break

    for dx, dy in zip(dxs, dys):
        nx = x + dx
        ny = y + dy

        if 0 <= nx < N and 0 <= ny < N:
            if virus[nx][ny] == 0: # 아직 방문 안 했으면
                virus[nx][ny] = vi # 증식
                queue.append((vi, second+1, nx, ny))

print(virus[X-1][Y-1])

