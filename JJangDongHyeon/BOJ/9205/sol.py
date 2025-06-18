

from collections import deque
# 테스트 케이스 개수 입력
T = int(input())

for tc in range(1, T + 1):
    convinience_num = int(input())
    que = deque()
    coor = []

    for _ in range(convinience_num + 2):
        x, y = map(int, input().split())
        coor.append((x,y))

    visited = [0] * len(coor)
    visited[0] = 1

    que.append(coor[0])
    end_x, end_y = coor.pop()


    while que:
        x, y = que.popleft()

        x_sum , y_sum = abs(end_x - x) , abs(end_y - y)

        if x_sum + y_sum <= 1000:
            print('happy')
            break


        for i in range(1, len(coor)):
            if visited[i]: continue
            convinience_x, convinience_y = coor[i][0], coor[i][1]

            x_sum, y_sum = abs(convinience_x - x) , abs(convinience_y - y)
            if x_sum + y_sum <= 1000:
                visited[i] = 1
                que.append((convinience_x, convinience_y))

    else:
        print('sad')

