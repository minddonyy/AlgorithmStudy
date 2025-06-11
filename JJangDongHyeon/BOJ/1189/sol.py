import sys

sys.stdin = open('input.txt')
#델타 탐색
dxy = [(0,1),(0,-1),(1,0),(-1,0)]
def dfs(start_x, start_y, max_distance, way_count):
    global count

    #방문 처리
    visited[start_x][start_y] = 1

    # 도착 지점 + 딱 맞는 횟수인짗 ㅔ크
    if (start_x == 0 and start_y == max_garo - 1) and (way_count == max_distance):
        count += 1
        return
    for dx, dy in dxy:
        next_y = start_y + dy
        next_x = start_x + dx

        # 리스트 범위 체크
        if not(0 <= next_y < max_garo and 0 <= next_x < max_sero) : continue

        # 벽체크
        if map[next_x][next_y] == 'T' : continue

        #카운트 넘는지 체크
        if way_count + 1 > max_distance: continue

        #방문 체크
        if visited[next_x][next_y] : continue

        # 갈 수 있으면 탐색
        dfs(next_x, next_y, max_distance, way_count + 1)

        # 갔다 왔으면 방문처리 다시 취소
        visited[next_x][next_y] = 0



max_sero, max_garo, max_distance = map(int, input().split())
visited = [[0] * max_garo for _ in range(max_sero)]

map = [input() for _ in range(max_sero)]
count = 0

dfs(max_sero - 1, 0, max_distance, 1)
print(count)