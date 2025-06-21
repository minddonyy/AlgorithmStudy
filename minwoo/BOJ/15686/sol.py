import sys
sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline
INF = 1e9


def dfs(depth, dist, index):
    global res
    if depth == M:
        res = min(res, sum(dist))
        return

    # 이전 인덱스 + 1부터, store 순회
    for i in range(index + 1, store_size):
        next_dist = dist[::]
        x, y = store[i]
        for idx, rc in enumerate(home):
            r, c = rc
            # 지금 유지하려는 치킨거리보다 현재 갱신되는 치긴거리가 작은지 확인
            now = abs(x - r) + abs(y - c)
            if next_dist[idx] <= now: continue
            next_dist[idx] = now
        dfs(depth+1, next_dist, i)


N, M = map(int, input().split())
store, home = [], []
grid = []
for i in range(N):
    temp = list(map(int, input().split()))
    grid.append(temp)
    for j in range(N):
        if temp[j] == 1:
            home.append((i, j))
        elif temp[j] == 2:
            store.append((i, j))
res = INF
store_size = len(store)
dfs(0, [1e7] * len(home), -1)
print(res)
