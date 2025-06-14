import sys
sys.stdin = open('input.txt')

# 테스트 케이스 개수 입력
T = int(input())

def day_count(start_idx):
    
    count = 1 #
    days_count = 1 #
    while goal_day_count > count: #목표 날짜 수 보다 카운트가 작을때 동안 반복

        start_idx = (start_idx + 1) % 7

        days_count += 1


        if days[start_idx]:
            count +=1

    return days_count

for tc in range(1, T + 1):
    goal_day_count = int(input()) # 목표로 채워야 하는 날짜 수 ( 수업 들은 날짜 )
    days = list(map(int, input().split()))

    min_count = float('inf') # 가장 낮은 카운트를 저장하기 위한 변수
    for i in range(7):
        if days[i]:
            days_count = day_count(i)
            min_count = min(min_count, days_count)

    print(f'#{tc} {min_count}')