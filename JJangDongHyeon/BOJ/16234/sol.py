import sys
sys.stdin = open('input.txt')

from collections import deque

def bfs(x,y, visited):
    que = deque([(x,y)])

    visited[x][y] = 1
    union = [(x,y)]
    union_total_sum = board[x][y]
    while que:
        x, y = que.popleft()

        for dx , dy in dxy:
            next_x, next_y = dx + x, dy + y

            if not(0 <= next_x < N and 0 <= next_y < N): continue
            if visited[next_x][next_y]: continue
            neighbor_minus = abs(board[x][y] - board[next_x][next_y])
            if L <= neighbor_minus <= R:
                que.append((next_x, next_y))
                visited[next_x][next_y] = 1
                union.append((next_x,next_y))
                union_total_sum += board[next_x][next_y]

    if len(union) != 1:
        new_population = union_total_sum // len(union)
        for union_x, union_y in union:
            board[union_x][union_y] = new_population
        return True

    return False



dxy = [(1, 0),(-1,0),(0,-1),(0,1)]
N, L, R = map(int, input().split())
#두 나라의 인구 차이가 L명 이상, R명 이하라면,

board = [list(map(int, input().split())) for _ in range(N)]
day_count = 0

while True:

    visited = [[0] * N for _ in range(N)]
    possible_move = False
    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                if bfs(i,j, visited):
                    possible_move = True

    if not possible_move:
        break
    day_count += 1

print(day_count)
