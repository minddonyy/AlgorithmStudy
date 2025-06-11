import sys
from collections import deque
sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline

n, w, L = map(int, input().split())
arr = list(map(int, input().split()))
q = deque([0] * w)
i = 0
weight, ans = 0, 0
while i < n:
    """
    1. popleft을 시킨다
    2. 현재 하중을 확인한다.
    2-1. 인덱스 트럭 + 현재 하중 >= L => 트럭 삽입 / 하중 증가
    2-2. 2-1이 false일 경우 0 삽입
    3. 종료: i값이 n이랑 일치하게 된다면.
    """
    weight -= q.popleft()
    if weight + (now := arr[i]) <= L:
        q.append(now)
        weight += now
        i += 1
    else:
        q.append(0)
    ans += 1
while q:
    q.popleft()
    ans += 1
print(ans)