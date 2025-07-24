"""02:54
세로 두 줄, 가로 N개 칸으로 이루어진 표
첫째 줄 각 칸은 1-N이 순서대로 들어있음
둘째 줄은 각 칸은 1이상 N이하인 정수가 들어있다

첫째 줄에서 숫자를 적절히 뽑으면 뽑힌 정수들이 이루는 집합과
뽑힌 정수들의 바로 밑의 둘째 줄에 들어있는 정수들이 이루는 집합이 일치

이 조건을 만족하는 정수를 최대로 많이 뽑는 방법을 출력

입력
N의 개수
N줄에 걸쳐 둘째줄 숫자가 주어짐

출력
가장 많이 뽑은 정수 개수
정수 오름차순 한줄에 한 개씩
"""
import sys
sys.stdin = open("2668.txt")

def search(start, now, path):
    # 방문처리
    visited[now] = 1
    path.append(now)
    next = second[now] # 탐색중인 숫자의 연결된 둘째줄 정수

    # 방문한적이 없으면 재귀
    if not visited[next]:
        search(start, next, path)
    elif next == start: # 사이클이 형성되면 결과값에 추가
        rst.append(path[:])

    # 백트래킹
    visited[now] = 0
    path.pop()

N = int(input())
first = [i for i in range(0, N+1)]
second = [0]
visited = [0 for _ in range(N+1)] # 방문여부

# 둘째줄 입력
for _ in range(N):
    second.append(int(input()))

rst = []
# dfs로 조건에 맞는 수찾기
for i in range(1, N+1):
    search(i, i, [])

# 결과 값 중복제거
rst2 = set()
for i in rst:
    for j in i:
        rst2.add(j)

rst2 = sorted(rst2)
# 출력
print(len(rst2))
for i in rst2:
    print(i)