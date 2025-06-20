import sys
sys.stdin = open('input.txt')

from collections import deque


dxy = [(0,1), (0,-1), (1,0), (-1,0)]

def find_virus():

    virus_coor = []
    for i in range(N):
        for j in range(N):
            if board[i][j] != 0:
                virus_coor.append((board[i][j], i, j, 0))
    virus_coor.sort()
    return deque(virus_coor)

def spread_virus(virus_coor):

    while virus_coor:
        virus_number, x, y, time = virus_coor.popleft()

        if time >= S:
            continue

        for dx, dy in dxy:
            next_x, next_y = dx + x, dy + y
            if not(0 <= next_x < N and 0 <= next_y < N): continue
            if board[next_x][next_y] != 0: continue
            board[next_x][next_y] = virus_number
            virus_coor.append((virus_number, next_x, next_y, time + 1))

N, K = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

S, result_x, result_y = map(int, input().split())




virus_coor = find_virus()

if len(virus_coor) > 0 :
    spread_virus(virus_coor)


print(board[result_x - 1][result_y - 1])