import sys
import heapq
sys.stdin = open("input.txt", "r")
input = sys.stdin.readline
INF = float('inf')
dxy = (0, 1), (1, 0), (0, -1), (-1, 0)


class Coord:
    def __init__(self):
        self.x = None
        self.y = None


def dijkstra():
    global grid, W, H
    hq = [(0, st.x, st.y)]
    distance = [[INF] * W for _ in range(H)]
    distance[st.x][st.y] = 0
    while hq:
        dist, x, y = heapq.heappop(hq)
        # print(f"현재 좌표 {x}, {y}, 현재 거리: {dist}")
        if dist > distance[x][y]: continue
        for dx, dy in dxy:
            nx, ny = x + dx, y + dy
            w = 0
            while True:
                if nx >= H or nx < 0 or ny >= W or ny < 0: break
                if (cell := grid[nx][ny]) == 'H' or distance[nx][ny] <= (acc := dist + w): break
                elif cell == 'R':
                    nx -= dx
                    ny -= dy
                    if (nx, ny) == (x, y): break
                    heapq.heappush(hq, (acc, nx, ny))
                    distance[nx][ny] = acc
                    break
                elif cell == 'E':
                    distance[nx][ny] = acc
                    break
                w += int(cell)
                nx += dx
                ny += dy
    if (res := distance[ed.x][ed.y]) != INF: return res
    return -1


W, H = map(int, input().split())
grid = [list(input().strip()) for _ in range(H)]
st, ed = Coord(), Coord()
for i in range(H):
    for j in range(W):
        if grid[i][j] == 'T':
            st.x, st.y = i, j
            grid[i][j] = 0
        elif grid[i][j] == 'E':
            ed.x, ed.y = i, j
# print(*grid, sep='\n')
print(dijkstra())

