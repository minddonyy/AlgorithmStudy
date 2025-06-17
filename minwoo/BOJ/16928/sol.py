import sys
from collections import deque
sys.stdin = open("input.txt", "r")

"""
주사위를 사용, 주사위의 각 면에는 1부터 6까지 수가 하나씩 적혀있다.
게임은 크기가 10 * 10
총 100개의 칸으로 나누어져 있는 보드판에서 진행

플레이어는 주사위를 굴려 나온 수 만큼 이동해야 한다
1. 플레이어가 i 칸에 있고 주사위 수가 4라면 i+4번 칸으로 이동해야 한다
2. 만약 주사위를 굴린 결과가 100번 칸을 넘어갔다면, 이동할 수 없다.
3. 도착한 칸이 사다리라면, 사다리를 타고 위로 올라간다.

뱀이 있는 칸에 도착하면, 뱀ㄴ을 따라서 내려가게 된다.
즉 사다리를 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 크고, 
뱀을 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 작아진다

결론
사다리를 최대한 이용할 수 있는 위치로만 이동할 수 있어야 한다.
"""


def bfs():
    global data
    q = deque([(1, 0)])
    visited = [0] * 109
    visited[1] = 1
    while q:
        # print(q)
        n, c = q.popleft()
        if n == 100:
            return c
        c += 1
        for i in range(1, 7):
            if data[(acc := n + i)] != 0:
                q.append((data[acc], c))
                visited[data[acc]] = 1
                continue
            if visited[acc] == 1:
                continue
            if acc > 100:
                continue
            q.append((acc, c))
            visited[acc] = 1


N, M = map(int, input().split())
data = [0] * 109
for _ in range(N+M):
    a, b = map(int, input().split())
    data[a] = b
print(bfs())
