"""
01:33
N*N크기에 지형 높이가 주어짐
최대한 긴 등산로 조성

규칙
1. 가장 높은 봉우리에서 시작
2. 높은 지형에서 낮은 지형으로 연결
3. 딱 한 곳을 정해 최대 K깊이만큼 지형 깎기 가능

입력
테케수 T
N, K
N*N지도
"""
xy = [(-1, 0), (1, 0), (0, -1), (0, 1)]
def search(i, j, length, kPass):
    global road
    matrixPass[i][j] = 1 # 현재 좌표 방문처리
    road = max(road, length) # 가장 긴 등산로면 갱신

    # 상, 하, 좌, 우로 탐색
    for xx, yy in xy:
        dx = i + xx
        dy = j + yy
        # 범위 안쪽이고, 방문한 적 없으면 통과
        if 0 > dx or dx >= N or 0 > dy or dy >= N or matrixPass[dx][dy]: continue
        # 다음 탐색좌표가 현재보다 지형이 작을 때
        if matrix[i][j] > matrix[dx][dy]:
            search(dx, dy, length+1, kPass)

        # 다음 탐색좌표가 현재보다 지형이 같거나 클 때 -> 깎기시도
        if matrix[i][j] <= matrix[dx][dy] and kPass:
            for loss in range(1, K+1):
                now = matrix[dx][dy] - loss

                # 지형이 0 이상 그리고 현재보다 작아야 함
                if now < 0 or now >= matrix[i][j]:continue
                original = matrix[dx][dy]
                matrix[dx][dy] = now
                search(dx, dy, length + 1, False)
                matrix[dx][dy] = original # 다음 탐색을 위해 복구

    matrixPass[i][j] = 0 # 현재 좌표 미방문처리

T = int(input())

for tc in range(1, T+1):
    N, K = list(map(int, input().split()))
    matrix = [list(map(int, input().split())) for _ in range(N)]
    road = 0

    # 가장 높은 봉우리 찾기
    high = 0 # 가장 높은 지형의 크기
    highXY = [] # 가장 높은 지형의 위치
    for i in range(N):
        for j in range(N):
            if high < matrix[i][j]:
                highXY.clear()
                highXY.append((i, j))
                high = matrix[i][j]
            elif high == matrix[i][j]:
                highXY.append((i, j))

    for i, j in highXY:
        matrixPass = [[0] * N for _ in range(N)] # 방문 처리 현황판
        search(i, j, 1, True)

    print(f"#{tc} {road}")