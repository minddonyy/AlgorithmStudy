from collections import deque

# BFS 함수 정의
def bfs():
    visited = [False] * max_val  # 방문 여부 확인 리스트
    visited[n] = True  # 시작 위치 방문 처리
    queue = deque([(n, 0)])  # (현재 위치, 이동 횟수)를 큐에 저장

    while queue:
        pos, count = queue.popleft()

        if pos == m:  # 목표 지점 도달 시 이동 횟수 반환
            return count

        # 가능한 이동 경우의 수
        for next_pos in [pos + 1, pos - 1, pos + a, pos - a, pos + b, pos - b, pos * a, pos * b]:
            if 0 <= next_pos < max_val and not visited[next_pos]:
                visited[next_pos] = True
                queue.append((next_pos, count + 1))  # 다음 위치와 이동 횟수 저장

# 입력 받기
a, b, n, m = map(int, input().split())
max_val = 100001  # 최대 범위 설정

result = bfs()  # BFS 실행

print(result)  # 최소 이동 횟수 출력