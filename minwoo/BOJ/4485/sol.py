import sys
import heapq
sys.stdin = open("input.txt", "r")
input = sys.stdin.readline
INF = float('inf')
dxy = (1, 0), (0, 1), (-1, 0), (0, -1)


def dijkstra():
    global N, grid
    distance = [[INF] * N for _ in range(N)]
    hq = []
    heapq.heappush(hq, ((x := grid[0][0]), 0, 0))
    distance[0][0] = x
    while hq:
        d, x, y = heapq.heappop(hq)
        if d > distance[x][y]:
            continue
        if x == N-1 and y == N-1:
            return d
        for dx, dy in dxy:
            nx, ny = x + dx, y + dy
            if nx >= N or nx < 0 or ny >= N or ny < 0:
                continue
            if (k := distance[nx][ny]) != INF:
                continue
            if (acc := d + grid[nx][ny]) >= k:
                continue
            heapq.heappush(hq, (acc, nx, ny))
            distance[nx][ny] = acc
    return


idx = 1
while True:
    N = int(input())
    if N == 0:
        break
    grid = [list(map(int, input().split())) for _ in range(N)]
    print(f"Problem {idx}: {dijkstra()}")
    idx += 1
