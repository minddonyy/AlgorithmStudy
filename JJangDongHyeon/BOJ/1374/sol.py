import sys
sys.stdin = open('input.txt')
import heapq

room_number = int(input())

room_info = []

for i in range(room_number):
    class_num , class_start_time, class_end_time = map(int,input().split())
    room_info.append((class_start_time, class_end_time))

room_info.sort()

# print(room_info)

heap = [room_info[0][1]]  # 첫 번째 강의의 종료 시간 미리 넣기

for i in range(1, len(room_info)):  # 두 번째 강의부터 반복
    start, end = room_info[i]
    if heap[0] <= start:
        heapq.heappop(heap)
    heapq.heappush(heap, end)

# heap 크기가 필요한 강의실 개수
print(len(heap))