import sys
sys.stdin = open('input.txt')

from collections import deque

ladder_num , snake_num = map(int, input().split())

jump_ladder_snake = dict()

for i in range(ladder_num + snake_num):
    start, end = map(int, input().split())
    jump_ladder_snake[start] = end


visited = [0] * 101 # 왜 보드칸은 100칸인데 101칸을 만드냐면, 인덱스 값을 숫자 그대로 쓰기 위해서임

queue = deque([(1, 0)]) # (현재 위치, 이동 횟수)

visited[1] = 1

while queue:
    current, jump_count = queue.popleft()

    if current == 100:
        print(jump_count)
        break

    for dice in range(1, 7): # 주사위는 1부터 6까지 있기때문
        next_pos = current + dice
        if next_pos > 100:
            continue

        # 사다리나 뱀이 있으면 해당 위치로 점프
        if next_pos in jump_ladder_snake:
            next_pos = jump_ladder_snake[next_pos]

        if not visited[next_pos]:
            visited[next_pos] = True
            queue.append((next_pos, jump_count + 1))