import sys
sys.stdin = open('input.txt')

def convert_time(h, m):
    return (h + 2) % 24, m

def simulate(h, m, remain):
    total_fee = 0

    while remain > 0:
        # 현재 시각 → 분으로 변환
        minutes = h * 60 + m

        # 00:00 ~ 04:59 사이 && 5시간 이상이면 정액권 사용
        if h <= 4 and remain > 300:
            used = 600 - minutes  # 10:00까지 남은 시간
            remain -= used
            h, m = 10, 0
            total_fee += 5000

        else:
            remain -= 60
            total_fee += 1000
            h = (h + 1) % 24  # 1시간 경과
            # m은 항상 0 유지 (정확히 한 시간 단위로 처리하므로)

    return total_fee

# 입력 처리
T = int(input())
for _ in range(T):
    time_str, D = input().split()
    h, m = map(int, time_str.split(":"))
    D = int(D)


    h, m = convert_time(h, m)
    print(simulate(h, m, D))