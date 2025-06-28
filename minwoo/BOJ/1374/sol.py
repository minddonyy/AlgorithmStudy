import sys
import heapq
sys.stdin = open("input.txt", "r")
input = sys.stdin.readline

N = int(input())
cls = sorted([tuple(map(int, input().split())) for _ in range(N)], key=lambda x: (x[1], x[2]))
# print(*cls, sep='\n')
# 여기서 해당 수업중에 교실이 몇개 필요한지 모름
# 수업의 종료와 시작이 같다면 그 교실은 1개만 써도 무관
# 시간순으로 따로 빼서 하기에서는 10억임
# 시작시간이 작은 순서대로 정렬하는게 옳을듯
hq = []
heapq.heapify(hq)
room, res, idx = 0, 0, 0
while idx < N:
    # 최소 강의실 개수가 아무리 많아봐야 10만개임
    # 특정 강의가 끝나는 시간을 hq에 삽입
    # 만약 현재 idx의 수업 시작시간보다 hq[0]의 종료시간이 더 빠르다면, hq.pop, res--
    # 아니라면 idx 꺼내서 수업 시작시키고 hq에 종료시간 삽입 idx++, res++

    if not hq or hq[0] > cls[idx][1]:   # 첫 시작 혹은 종료시간보다 시작시간이 빠른 경우, cls만 꺼낸다.
        heapq.heappush(hq, cls[idx][2])
        room += 1
        idx += 1
    elif hq[0] == cls[idx][2]:  # 같은 경우 hq와 cls 모두 꺼낸다
        heapq.heappop(hq)
        heapq.heappush(hq, cls[idx][2])
        idx += 1
    else:   # 종료시간이 더 빠른 경우, hq만 꺼낸다.
        heapq.heappop(hq)
        room -= 1
    res = max(res, room)
print(res)
