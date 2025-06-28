import sys
sys.stdin = open('input.txt')


N = int(input())
T = input()

answer = []
balance = 0  # S: +1, U: -1

# 1. 현재 커서의 위치에 SU 를 추가한다. == S
# 2. 커서가 맨 왼쪽에 있지 않은 경우, 커서를 왼쪽으로 한 글자 움직인다. == N
# 3. 현재 커서의 위치에 US 를 추가한다. == U

for ch in reversed(T):
    if ch == 'S':
        if balance >= 0:
            answer.append('U')  # "US" 만들기  U 시도
            answer.append('N')
        elif balance < 0:
            answer.append('N')
        balance += 1
    elif ch == 'U':
        if balance <= 0:
            answer.append('S')  # "SU" 만들기  S 시도
            answer.append('N')
        elif balance > 0:
            answer.append('N')
        balance -= 1

print(len(answer))
print(''.join(answer))