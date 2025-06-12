import sys
import heapq
input = sys.stdin.readline
INF = float('inf')
MAX = 100000

def bfs():
    hq = [(0, N)]
    visited[N] = 0
    while hq:
        dist, cur = heapq.heappop(hq)
        if cur == M:
            return dist
        if dist > visited[cur]:
            continue
        moves = [
            cur + 1, cur - 1,
            cur + A, cur - A,
            cur + B, cur - B,
            cur * A, cur * B,
        ]
        dist += 1
        for nxt in moves:
            if nxt < 0 or nxt > MAX: continue
            if dist >= visited[nxt]: continue
            heapq.heappush(hq, (dist, nxt))
            visited[nxt] = dist

A, B, N, M = map(int, input().split())
visited = [INF] * (MAX + 1)

print(bfs())