from collections import deque

def bfs(locations, n):
    visited = [0] * (n + 2)
    queue = deque()
    queue.append(0)
    visited[0] = 1

    while queue:
        now = queue.popleft()
        for i in range(1, n + 2):
            if not visited[i]:
                dist = abs(locations[now][0] - locations[i][0]) + abs(locations[now][1] - locations[i][1])
                if dist <= 1000:
                    visited[i] = 1
                    queue.append(i)

    if visited[n + 1]:
        return "happy"
    else:
        return "sad"

t = int(input())
for _ in range(t):
    n = int(input())
    locations = [list(map(int, input().split())) for _ in range(n + 2)]
    result = bfs(locations, n)
    print(result)
