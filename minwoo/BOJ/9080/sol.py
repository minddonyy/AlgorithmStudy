T = int(input())
for t in range(T):
    # 22시부터 야간 요금제(5000원 내고) 다음날 아침 8시까지 사용
    # 시간당 1000원
    # 22시부터 5시간 안넘으면 똑같고
    HHMM, time = input().split()
    h, m = map(int, HHMM.split(':'))
    # 시간 +1 씩 하면서, 22시를 넘었는데 6시간 이상 남았다면, 정액제로 전환 후 아침 8시로 만들기
    time = int(time)
    fee = 0
    while time > 0:
        # 현재 시간이 야간 && 남은 play 시간이 5시간 이상
        rh, rm = (h+2) % 24, m
        rotated_min = rh * 60 + rm
        if 0 <= rh <= 4 and time > 300:
            jump = 600 - rotated_min
            fee += 5000
            time -= jump

            h, m = 8, 0
        else:
            fee += 1000
            time -= 60
            h = (h + 1) % 24
    print(fee)