import sys
from collections import deque
sys.stdin = open('input.txt')


truck_num, bridge_length, bridge_max_weight = map(int, input().split())
trucks = deque(map(int, input().split()))

current_bridge = deque([0] * bridge_length)

# 현재 다리위에 있는 트럭들의 무게 합인데, 맨 처음 sum(current_bridge) 하면 너무 오래걸릴까봐... 바꿈
current_bridge_weight_sum = 0


time = 0
# print(trucks)
# print(current_bridge)


# 현재 다리의 상태가 빌때까지 반복문
while current_bridge:
    time += 1

    # 만약 트럭이 없다면 현재 다리(데큐)만 남아 있는 거니까 무한 루프 돌 일이 없음.
    current_bridge_weight_sum -= current_bridge.popleft()

    #아직 다리를 지나가지 않은 트럭이 있다면
    if trucks:
        # if sum(current_bridge) + trucks[0] <= bridge_max_weight:

        #현재 다리 위에 있는 무게 + 트럭 리스트에 있는 맨 처음 무게의 합을 보고
        if current_bridge_weight_sum + trucks[0] <= bridge_max_weight:

            # 맨 앞의 트럭을 빼서
            truck = trucks.popleft()

            # 현재 다리에 트럭을 넣는다.
            current_bridge.append(truck)

            # 그리고 현재 다리 무게의 합에다가 금방 빼낸 트럭의 무게를 더함
            current_bridge_weight_sum += truck


        # 맨 앞의 트럭의 무게 + 현재 다리위에 있는 무게의 합이 한계보다 초과하면 24번 줄에서 현재 다리 데큐를 popleft만 해버려서 다리의 길이가 달라짐, 그래서 0을 하나 넣어줘서 크기를 맞춤
        else:
            current_bridge.append(0)


print(time)