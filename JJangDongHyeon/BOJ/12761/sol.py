
from collections import deque


A, B, donggyue,joomi = map(int, input().split())

if donggyue == joomi:
    print(0)
    exit()

# visited = [0] * (joomi + 1)
MAX = 100001
visited = [0] * MAX
visited[donggyue] = 1

que = deque([(donggyue, 0)])
while que:
    current_donggyue, count = que.popleft()

    if current_donggyue == joomi:
        print(count)
        exit()

    for next_donggyue in [
        current_donggyue - 1, current_donggyue + 1,
        current_donggyue - A, current_donggyue + A,
        current_donggyue - B, current_donggyue + B,
        current_donggyue * A, current_donggyue * B
    ]:

        if not(0 <= next_donggyue < MAX): continue

        if visited[next_donggyue]: continue
        visited[next_donggyue] = 1
        que.append((next_donggyue, count + 1))



