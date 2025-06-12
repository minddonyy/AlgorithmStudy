from collections import deque

n, w, l = map(int, input().split())  # 트럭 수, 다리 길이, 최대 하중
trucks = deque(list(map(int, input().split())))  # 대기 중인 트럭들
bridge = deque([0] * w)  # 다리 상태 (처음엔 빈 공간)
cur_l = 0  # 현재 다리 위 총 무게
time = 0  # 경과 시간

while bridge:
    time += 1  # 시간 경과
    out = bridge.popleft()  # 다리에서 한 칸 이동
    cur_l -= out  # 나간 트럭 무게 차감

    if trucks:
        if cur_l + trucks[0] <= l:  # 다음 트럭 진입 가능 여부
            truck = trucks.popleft()
            bridge.append(truck)
            cur_l += truck
        else:
            bridge.append(0)  # 진입 불가 시 빈 공간 추가

print(time)
