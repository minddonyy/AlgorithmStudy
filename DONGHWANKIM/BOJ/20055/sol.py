import sys
sys.stdin = open("input.txt", "r")

T = int(input())
for test_case in range(1, T + 1):
    N, K = map(int, input().split())
    HP = list(map(int, input().split())) # 컨베이어 내구도
    robots = [False] * N                 # 컨베이어 위 로봇 유무

    cnt = 0                              # 컨베이어 카운팅

    while True:
        cnt += 1

        HP = [HP[-1]] + HP[:-1]          # 컨베이어 돌아가는 거에 맞춰 내구도도 돌아감
        robots = [False] + robots[:-1]   # 로봇도 마찬가지, 상차 자리 앞에는 무조건 빈칸 시작
        robots[-1] = False               # 로봇 하차


        for i in range(N-1, -1, -1):     # 로봇들 칸 이동
            if robots[i] and not robots[i + 1] and HP[i + 1] > 0: # 앞으로 옮길 수 있는지 점검
                robots[i] = False
                robots[i + 1] = True
                HP[i + 1] -= 1 # 되면 옮기고 내구도 감소
        robots[-1] = False     # 제일 앞에 있는 로봇 하차


        if HP[0] > 0 and not robots[0]: # 로봇 상차자리 내구도 있고 로봇 없으면 상차
            robots[0] = True
            HP[0] -= 1 # 내구도 깎음

        if HP.count(0) >= K:  # 내구도 0이 K 이상이면 카운팅 출력
            print(cnt)
            break


