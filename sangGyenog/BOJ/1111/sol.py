"""
01:49
수열이 주어질 때 다음 수를 찾는 문제
항상 모든 답은 *a+b이고, a, b는 정수
수 N개가 주어질 때 다음 수를 출력
다음 수가 여러 개면 A, 구할 수 없는 경우 B출력

입력
수열의 개수 N <= 50
N개의 수가 주어짐 <= 100
"""
import sys
sys.stdin = open("1111.txt")

def search(num, N):
    abList = set()
    for i in range(N-2):
        div1 = num[i+2] - num[i+1]
        div2 = num[i+1] - num[i]
        if div2 != 0 and div1 % div2 == 0:
            subA = div1 // div2
            subB = num[i+1] - (num[i] * subA)
            abList.add((subA, subB))
    return abList
def check(a, b, num, N):
    # 전체를 순회하며 맞는지 확인
    for i in range(N - 1):
        if num[i] * a + b != num[i + 1]:
            return False
    return True
N = int(input())
num = list(map(int, input().split()))

if N >= 3:
    if all(x == num[0] for x in num): # 모두 같은지 판별
        print(num[0])
    else:
        # 연립방정식으로 a, b를 구한다
        abList = search(num, N)
        # 모든 해를 순회해보며 적용이 되는지 확인
        ab = [(a, b) for (a, b) in abList if check(a, b, num, N)]

        if len(ab) == 0:
            print("B")
        elif len(ab) == 1:
            a, b = ab[0]
            print(num[-1] * a + b)
        else:
            print("A")
elif N == 2:
    if num[0] == num[1]:
        print(num[0])
    else:
        print("A")
else:
    print("A")
