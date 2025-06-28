import sys
from collections import deque
sys.stdin = open("input.txt", "r")
input = sys.stdin.readline
dxy = (1, 0), (0, 1), (-1, 0), (0, -1)


def search_passenger():
    global grid, now_x, now_y, dxy, N
    if (c := grid[now_x][now_y]) != 0:
        grid[now_x][now_y] = 0
        return c, 0
    visited = [[0] * N for _ in range(N)]
    dq = deque([(now_x, now_y, 0)])
    visited[now_x][now_y] = 1
    candidates = []
    min_dist = -1
    while dq:
        x, y, dist = dq.popleft()
        if (c := grid[x][y]) != 0:
            if min_dist == -1:
                min_dist = dist
            if min_dist == dist:
                candidates.append((dist, x, y, c))
        if -1 < min_dist < dist:
            break
        for dx, dy in dxy:
            nx, ny = x + dx, y + dy
            if nx >= N or nx < 0 or ny >= N or ny < 0:
                continue
            if visited[nx][ny] == 1 or grid[nx][ny] == 1: continue
            dq.append((nx, ny, dist+1))
            visited[nx][ny] = 1
    if not candidates:
        return (), 1e9
    candidates.sort(key=lambda cur: (cur[1], cur[2]))
    res = candidates[0]
    # print(pas, res)
    now_x, now_y = res[1], res[2]
    grid[now_x][now_y] = 0
    return res[3], res[0]


def arrive_passenger(exy):
    global grid, N, now_x, now_y
    if exy == (now_x, now_y):
        return 0
    visited = [[0] * N for _ in range(N)]
    dq = deque([(now_x, now_y, 0)])
    visited[now_x][now_y] = 1
    dist = -1
    while dq:
        x, y, dist = dq.popleft()
        if (x, y) == exy:
            now_x, now_y = exy
            break
        for dx, dy in dxy:
            nx, ny = x + dx, y + dy
            if nx >= N or nx < 0 or ny >= N or ny < 0:
                continue
            if visited[nx][ny] == 1 or grid[nx][ny] == 1: continue
            dq.append((nx, ny, dist+1))
            visited[nx][ny] = 1
    if (now_x, now_y) != exy:
        return 1e9
    return dist


def run(fuel):
    global M, N

    def is_not_fuel(val):
        return val < 0
    count = 0
    while count < M:
        # print(*grid, sep='\n')
        arrival, dist = search_passenger()
        fuel -= dist
        # print(f'승차: {count+1}번; 남은 연료 {fuel}, 이동거리 {dist}, 현재 위치 {now_x, now_y}, 도착지: {arrival}')
        if is_not_fuel(fuel):    # 종료조건 확인
            return -1
        dist = arrive_passenger(arrival)
        fuel -= dist
        # print(f'하차: {count + 1}번; 남은 연료 {fuel}, 이동거리 {dist}, 현재 위치 {now_x, now_y}')
        if is_not_fuel(fuel):
            return -1
        fuel += dist * 2
        count += 1
    return fuel


N, M, F = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]
now_x, now_y = map(int, input().split())
now_x, now_y = now_x - 1, now_y - 1
for _ in range(M):
    l, m, n, o = map(int, input().split())
    grid[l-1][m-1] = (n-1, o-1)
print(run(F))
