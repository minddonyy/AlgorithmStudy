import sys
input = sys.stdin.readline


def dfs(start_x, start_y, visited):

    # 도착지점에 온다면 1을 리턴해서, 여길 지나쳤던 모든 경로에 1을 더합니다.
    if start_x == sero - 1 and start_y == garo - 1:
        return 1

    # 만약 이미 왔던 곳이란걸 체크 할떄는 -1이 아닌지를 봅니다.
    # 1. 이 곳이 0 이라면 이미 도착 지점에 못 왔다는 뜻이니까 (dfs는 한 곳만 죽어라 팜) 밑에 작업에서 지금 좌표에 +0을 해도 지장이 없음
    # 2. 이 곳이 0 이아니라 다른 정수라면 이 좌표의 도착 가능 경로수를 가지고 리턴해서 더해줍니다.
    if visited[start_x][start_y] != -1:
        return visited[start_x][start_y]

    #이게 방문처리를 하는 것임 -1 에서 0으로,
    #맨 처음에 visited를 0으로 만든다면, 경로 수가 계산 된 곳인지, 아직 안 온 곳인지 알 수가 없음.

    visited[start_x][start_y] = 0
    for dx, dy in dxy:
        next_x, next_y = dx + start_x, dy + start_y

        if not(0 <= next_x < sero and 0 <= next_y < garo): continue
        if board [start_x][start_y] <= board [next_x][next_y]: continue

        # 결국 여기서, map[0][0]에서 dfs를 시작해서 가장 처음 도착 지점에 도착한다면, 그 경로에 1을 새기고,
        # 그 경로가 도착을 못한다면 0으로만 된다.(방문처리)
        # 만약 갔던 경로가 0이 아니라 다른 양수라면 그 겹치는 길로 갔을때 도착 할 수 있다는 뜻이니까
        # 그걸 더해서 자신의 visited에 저장한다.
        # 결국 타고타고타고 해서 맨 처음 visited[0][0]에 갈 수 있는 경로의 수가 저장되는 것.
        visited[start_x][start_y] += dfs(next_x,next_y,visited)

    return visited[start_x][start_y]
sero, garo = map(int, input().split())

board  = [list(map(int, input().split())) for _ in range(sero)]

dxy = [(0,1),(0,-1),(1,0),(-1,0)]

visited = [[-1] * garo for _ in range(sero)]

dfs(0,0,visited)
print(visited[0][0])