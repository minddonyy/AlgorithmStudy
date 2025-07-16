import sys
input = sys.stdin.readline
# sys.stdin = open('input.txt')
from collections import deque

def bfs():
    baby_x, baby_y = baby_shark_info['coor']
    size = baby_shark_info['size']
    possible_fish_coor = []
    visited = [[-1] * N for _ in range(N)]
    visited[baby_x][baby_y] = 0
    que = deque([(baby_x,baby_y)])


    while que:
        x, y = que.popleft()

        for dx, dy in dxy:
            nx, ny = dx + x, dy + y

            if not(0 <= nx < N and 0 <= ny < N): continue
            if visited[nx][ny] != -1: continue
            if board[nx][ny] > size: continue
            visited[nx][ny] = visited[x][y] + 1
            que.append((nx,ny))
            if 0 < board[nx][ny] < size:
                possible_fish_coor.append((visited[nx][ny], nx, ny))

    if not possible_fish_coor:
        return False

    possible_fish_coor.sort()
    return possible_fish_coor[0]





N = int(input())
board = [list(map(int, input().split())) for _ in range(N)]
dxy = [(0, 1),(0, -1),(1, 0),(-1, 0)]
# 가장 처음에 아기 상어의 크기는 2
time = 0

baby_shark_info = dict()

for i in range(N):
    for j in range(N):
        if board[i][j] == 9:
            baby_shark_info["coor"] = (i,j)
            baby_shark_info["size"] = 2
            baby_shark_info['eat_count'] = 0
            # baby_shark_x, baby_shark_y = i, j
            board[i][j] = 0


while True:
    possible_result = bfs()

    if not possible_result:
        break

    min_dist, next_shark_x, next_shark_y = possible_result
    time += min_dist
    board[next_shark_x][next_shark_y] = 0
    baby_shark_info['coor'] = (next_shark_x, next_shark_y)
    baby_shark_info['eat_count'] += 1

    if baby_shark_info['size'] == baby_shark_info['eat_count']:
        baby_shark_info['size'] += 1
        baby_shark_info['eat_count'] = 0


print(time)