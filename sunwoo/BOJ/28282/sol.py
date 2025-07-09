# x : 한 바구니에 있는 양말 개수 / k : 양말의 색 종류 수
x, k = map(int, input().split())
# 총 2x개의 양말 색 정보 입력받기 (앞의 x개는 왼쪽, 뒤의 x개는 오른쪽)
sock_colors = list(map(int, input().split()))

# 왼쪽 양말: 0 ~ x-1 / 오른쪽 양말: x ~ 2x-1
left_socks = sock_colors[:x]
right_socks = sock_colors[x:]

# 왼쪽, 오른쪽 같은 양말 색 갯수 저장할 딕셔너리
left_cnt = {}
right_cnt = {}

# 왼쪽 양말 색 개수 세기
for color in left_socks:
    if color not in left_cnt:
        left_cnt[color] = 0
    left_cnt[color] += 1

# 오른쪽 양말 색 개수 세기
for color in right_socks:
    if color not in right_cnt:
        right_cnt[color] = 0
    right_cnt[color] += 1

# 모든 경우의 수
all_cases = x * x

# 같은 쌍의 수를 누적할 변수
same_pair = 0
for num in range(1, k+1):
    # get()메서드로 왼쪽 양말 색 num의 개수 x 오른쪽 양말 색 num의 개수를 가지고 와서
    # wame_pair 변수에 누적한다
    # 만약 num이 왼쪽 양말 or 오른쪽 양말 딕셔너리에 없으면 0 반환
    same_pair += left_cnt.get(num, 0) * right_cnt.get(num, 0)

# 결과 출력
print(all_cases - same_pair)
