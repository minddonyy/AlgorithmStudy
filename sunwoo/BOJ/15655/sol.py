def dfs(depth, idx):
    # m개 수를 선택했으면 출력
    if depth == m:
        print(*temp)
        return
    
    # idx(0) 부터 n까지 탐색
    for i in range(idx, n):
        temp.append(nums[i]) # 숫자 선택 한거 담기
        dfs(depth + 1, i + 1) # 다음 숫자 선택해야하니 +1 해서 재귀 호출
        temp.pop() # 재귀 끝나면 백트래킹

# n: 숫자 개수 m: 골라야하는 개수
n, m = map(int, input().split())
# n개의 수 리스트
nums = list(map(int, input().split()))
# 오름차순이라 정렬
nums.sort()
# 선택한 숫자를 저장할 빈 리스트
temp = []

# dfs 호출
dfs(0, 0)
