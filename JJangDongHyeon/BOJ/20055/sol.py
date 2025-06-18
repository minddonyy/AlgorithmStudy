
from collections import deque


belt_N , limit_broken = map(int, input().split())
belt_que = deque(list(map(int, input().split())))
robots = deque([0] * belt_N)



count = 0
time = 0
while count < limit_broken:
    time += 1
    # 1. 벨트가 각 칸 위에 있는 로봇과 함께 한 칸 회전한다.
    belt_que.rotate(1)
    robots.rotate(1)
    # 1-1. 로봇이 내리는 위치에 오면 "이유 불문 무조건 내린다"
    robots[belt_N - 1] = 0
    # 2. 로봇의 자체 이동
    #   가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
    # - 근데 이걸 하려면 일단 역 순으로 해야함! 만약 맨 처음 로봇 부터 한칸 옆으로 이동시키면 로봇이 충돌이 나기 때문.
    for i in range(belt_N - 2, -1, -1):
        # 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
        if robots[i] > 0 and robots[i + 1] == 0 and belt_que[i + 1] > 0:
            robots[i] = 0
            robots[i + 1] = 1
            belt_que[i + 1] -= 1
            # 내구도가 0 이되면 카운트를 하나 올린다.
            if belt_que[i + 1] == 0:
                count += 1
    # 로봇 자체 이동 후 내리는 위치에 오면 즉시 내린다.
    robots[belt_N - 1] = 0

    #내구도가 0 이 아니라면 로봇을 올린다.
    if belt_que[0] > 0:
        robots[0] = 1
        belt_que[0] -= 1
        # 내구도가 0 이되면 카운트를 하나 올린다.
        if belt_que[0] == 0:
            count += 1
print(time)







