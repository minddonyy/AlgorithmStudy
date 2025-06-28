from itertools import combinations

def make_combi_set(s, k):
    return set(''.join(c) for c in combinations(s, k))

X = input().strip()
Y = input().strip()
Z = input().strip()
k = int(input())

x_combi = make_combi_set(X, k)
y_combi = make_combi_set(Y, k)
z_combi = make_combi_set(Z, k)

all = list(x_combi) + list(y_combi) + list(z_combi)

count = {}
for c in all:
    if c in count:
        count[c] += 1
    else:
        count[c] = 1

result = sorted([c for c in count if count[c] >= 2])

if result:
    for r in result:
        print(r)
else:
    print(-1)
