from itertools import combinations

def get_chicken_distance(combi):
    total = 0
    for hx, hy in houses:
        min_dist = 99999999999
        for cx, cy in combi:
            dist = abs(hx - cx) + abs(hy - cy)
            if dist < min_dist:
                min_dist = dist
        total += min_dist
    return total

n, m = map(int, input().split())
city = []
for _ in range(n):
    city.append(list(map(int, input().split())))

houses = []
chickens = []

for i in range(n):
    for j in range(n):
        if city[i][j] == 1:
            houses.append((i, j))
        elif city[i][j] == 2:
            chickens.append((i, j))

result = 99999999999
for combi in combinations(chickens, m):
    dist = get_chicken_distance(combi)
    if dist < result:
        result = dist

print(result)
