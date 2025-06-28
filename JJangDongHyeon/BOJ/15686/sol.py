import sys
from collections import deque
sys.stdin = open('input.txt')
def bfs(selected):
    global home_coor
    distance_sum = 0

    for start_x, start_y in home_coor:
        min_dist = 99999999
        for selected_x, selected_y in selected:
            distance = abs(selected_x - start_x) + abs(selected_y - start_y)
            min_dist = min(min_dist, distance)
        distance_sum += min_dist

    return distance_sum




def combination(start, selected):

    if len(selected) == limit_store:
        global min_distance
        distance_sum = bfs(selected)
        min_distance = min(distance_sum, min_distance)
    for i in range(start, len(store_coor)):
        combination(i + 1, selected + [store_coor[i]])

dxy = [(0,1),(0,-1),(1,0),(-1,0)]

N, limit_store = map(int, input().split())

board = [list(map(int, input().split())) for _ in range(N)]
store_coor = []
home_coor = []
min_distance = 99999999
for i in range(N):
    for j in range(N):
        if board[i][j] == 2:
            store_coor.append((i,j))
        if board[i][j] == 1:
            home_coor.append((i,j))
combination(0, [])

print(min_distance)