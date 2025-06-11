### 문제 설명
- 문제 : 컴백홈
- 플랫폼: 백준
- 난이도 : 실버 I
- 시간 : 116ms
- 메모리 : 32412KB

### 코드
```
# 상하좌우 이동 방향 (북, 동, 남, 서)
drc = [[-1, 0], [0, 1], [1, 0], [0, -1]]

# 백트래킹 함수: depth는 현재 이동한 칸 수
def backtracking(depth, row, col):
    global result

    # 목표 거리 도달 시 도착 위치 확인
    if depth == k:
        if row == er and col == ec:
            result += 1
        return

    # 4방향 이동 시도
    for dr, dc in drc:
        nr, nc = row + dr, col + dc

        # 범위 내이고, 방문하지 않았으며, T가 아닐 때
        if 0 <= nr < r and 0 <= nc < c:
            if not visited[nr][nc] and grid[nr][nc] != 'T':
                visited[nr][nc] = True  # 방문 표시
                backtracking(depth + 1, nr, nc)  # 다음 칸으로 이동
                visited[nr][nc] = False  # 되돌아오기 (백트래킹)

# 입력 처리
r, c, k = map(int, input().split())
grid = [input() for _ in range(r)]

# 시작점 (왼쪽 아래), 도착점 (오른쪽 위)
sr, sc = r - 1, 0
er, ec = 0, c - 1

# 방문 체크 배열 초기화
visited = [[False] * c for _ in range(r)]
visited[sr][sc] = True  # 시작점 방문 처리

result = 0  # 경로 수 결과값

backtracking(1, sr, sc)

print(result)
```


### 풀이 방식
주석 참고

---
* PR 제목은 커밋 메시지와 통일합니다.
