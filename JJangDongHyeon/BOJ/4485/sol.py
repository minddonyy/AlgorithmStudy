import sys
sys.stdin = open('input.txt')

import heapq


def zela_heap(start_cost, start_x, start_y):
    visited[start_x][start_y] = board[start_x][start_y]
    stack = [(start_cost, start_x, start_y)]
    # stack.heappush(stack, (start_cost, start_x, start_y))
    heapq.heapify(stack)
    while stack:
        cost, x, y = heapq.heappop(stack)

        if x == n - 1 and y == n - 1:
            return cost

        for dx, dy in dxy:
            next_x, next_y = x + dx, y + dy

            if not (0 <= next_x < n and 0 <= next_y < n): continue
            new_cost = cost + board[next_x][next_y]
            if new_cost >= visited[next_x][next_y]: continue
            visited[next_x][next_y] = new_cost
            heapq.heappush(stack, (new_cost, next_x, next_y))

dxy = [(0,1),(0,-1),(1,0),(-1,0)]
tc = 0
while True:
    tc += 1

    n = int(input())
    if n == 0:
        exit()
    board = [list(map(int, input().split())) for _ in range(n)]
    visited = [[2241] * n for _ in range(n)]
    # 왜 2241이냐면.... 격자의 수가 총 125 까지고, 각 칸에 들어가는 정수가
    #최대 9래서 (125 * 9) + (124 * 9) =2241, 이렇게 최대 결과가 나올 수 있다고 계산했슴니다.


    cost = zela_heap(board[0][0], 0, 0)

    print(f'Problem {tc}: {cost}')
    continue


