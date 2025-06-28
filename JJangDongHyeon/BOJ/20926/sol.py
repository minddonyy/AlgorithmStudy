import sys
import heapq

input = sys.stdin.readline
INF = float('inf')

dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

def skating(x, y, direction, cost):
    cur_cost = 0
    nx, ny = x, y

    while True:
        nx += dx[direction]
        ny += dy[direction]

        if not (0 <= nx < height and 0 <= ny < width): return None
        cell = board[nx][ny]

        if cell == 'H': return None

        if cell == 'R':
            nx -= dx[direction]
            ny -= dy[direction]
            break

        if cell == 'E':
            break

        # 숫자일 때만 비용 추가
        if cell.isdigit():
            cur_cost += int(cell)

        # 가지치기: 이미 더 적은 비용으로 도달한 적 있으면 중단
        if visited[nx][ny] <= cost + cur_cost:
            return None

    return nx, ny, cost + cur_cost

# 입력
width, height = map(int, input().split())
board = [list(input().strip()) for _ in range(height)]

# 시작점, 도착점 찾기
for i in range(height):
    for j in range(width):
        if board[i][j] == 'T':
            start = (i, j)
            board[i][j] = '0'  # 숫자로 간주하기 위해 문자열로 0으로 처리
        elif board[i][j] == 'E':
            end = (i, j)

# 다익스트라
visited = [[INF] * width for _ in range(height)]
heap = [(0, start[0], start[1])]
visited[start[0]][start[1]] = 0

while heap:
    cost, x, y = heapq.heappop(heap)

    if (x, y) == end:
        print(cost)
        break

    if cost > visited[x][y]:
        continue

    for direction in range(4):
        result = skating(x, y, direction, cost)
        if not result:
            continue
        nx, ny, total_cost = result
        if visited[nx][ny] > total_cost:
            visited[nx][ny] = total_cost
            heapq.heappush(heap, (total_cost, nx, ny))
else:
    print(-1)
