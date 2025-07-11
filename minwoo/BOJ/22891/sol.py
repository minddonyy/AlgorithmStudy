import sys
input = sys.stdin.readline

n, k = map(int, input().split())
v = sorted(list(map(int, input().split())))

res = 1e18
for i in range(1, n):
    team = (v[0] * i) + (v[i] * (n-i))
    c = (k // team) + (0 if k % team == 0 else 1)
    res = min(res, c)
print(res)