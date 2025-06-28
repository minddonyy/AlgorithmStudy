import sys
import heapq
sys.stdin = open('input.txt', 'r')

N, M = map(int, input().split())
hq = []
for i in list(map(int, input().split())):
    heapq.heappush(hq, i)
for i in range(M):
    x, y = heapq.heappop(hq), heapq.heappop(hq)
    heapq.heappush(hq, x + y)
    heapq.heappush(hq, x + y)
print(sum(hq))