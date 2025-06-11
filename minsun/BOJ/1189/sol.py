import sys
sys.stdin = open('input.txt', 'r')
"""
첫 줄에 정수 R(1 ≤ R ≤ 5), C(1 ≤ C ≤ 5), K(1 ≤ K ≤ R×C)가 공백으로 구분되어 주어진다. 
두 번째부터 R+1번째 줄까지는 R×C 맵의 정보를 나타내는 '.'과 'T'로 구성된 길이가 C인 문자열이 주어진다.
"""
dxs = [-1, 1, 0, 0]
dys = [0, 0, -1, 1]

def gohome(start_x, start_y, cnt): # 시작위치와 카운트
    global result
    visited[start_x][start_y] = 1

    # 도착 확인하면 result에 +1 해줘야 함
    if start_x == 0 and start_y == (C - 1):
        if cnt == K:
            result += 1
        return

    #델타탐색 .. 이거 눈감고도 하던 건데 오래만에 하니까 와 ... 반성합니다
    for dx, dy in zip(dxs, dys):
        nx = start_x + dx
        ny = start_y + dy

        # 범위 체크... 하고 방문과 T가 아닌거
        if 0 <= nx < R and 0 <= ny < C and visited[nx][ny] != 1 and hansu_map[nx][ny] != 'T':
            visited[nx][ny] = 1 #방문
            gohome(nx, ny, cnt + 1) # 다음칸
            visited[nx][ny] = 0 # 다시 방문취소해주고

# 입력 받고
R, C, K = map(int, input().split())
hansu_map = [list(map(str, input().strip())) for _ in range(R)]
# 방문 배열 생성
visited = [[0]*C for _ in range(R)]
result = 0
gohome(R-1, 0, 1) # DFS 들어갑니다
print(result)



