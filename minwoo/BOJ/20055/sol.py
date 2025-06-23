import sys
from collections import deque
sys.stdin = open('input.txt', 'r')
input = sys.stdin.readline


def run_conv():
    global conv, N, K
    time = 1
    robot = deque([0] * N)
    while True:
        # 1. 벨트가 로봇과 함께 한 칸 회전
        conv.rotate(1)
        robot.pop()
        robot.appendleft(0)
        robot[-1] = 0
        # 2. 가장 먼저 벨트에 올라간 로봇부터(끝까지 이동한 로봇은 내림)(N-2부터 -1까지)
        for i in range(N-2, -1, -1):
            if robot[i] == 0: continue
            # 이동하려는 칸의 내구도가 0이거나, 로봇이 있다면 pass
            if conv[i + 1] == 0 or robot[i + 1] == 1:
                continue
            robot[i] = 0
            conv[i+1] -= 1
            # i+1 값이 N-1이라면 로봇은 컨베이어에서 내린다.
            # 내리면 갱신하지 않는다.
            if i+1 != N-1:
                robot[i+1] = 1
        # 3. 올리는 위치 내구도가 0이 아니라면 로봇을 올림
        if conv[0] != 0:
            robot[0] = 1
            conv[0] -= 1
        # 4. 내구도가 0인 칸을 확인
        if conv.count(0) >= K:
            return time
        time += 1


N, K = map(int, input().split())
conv = deque(list(map(int, input().split())))
print(run_conv())