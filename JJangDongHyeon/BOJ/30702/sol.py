import sys
sys.stdin = open('input.txt')

def A_dfs(start_x, start_y,start_char):
    # A를 dfs 돌아서 그 좌표값들을 넘겨주는 함수
    A_box = {(start_x, start_y)}
    stack = [(start_x, start_y)]

    A_visited[start_x][start_y] = 1
    while stack:
        x, y = stack.pop()

        for dx, dy in dxy:
            next_x , next_y = dx + x , dy + y

            if not(0 <= next_x < sero and 0 <= next_y < garo): continue
            if A_visited[next_x][next_y]: continue
            if A[next_x][next_y] != start_char: continue
            A_visited[next_x][next_y] = 1
            stack.append((next_x, next_y))
            A_box.add((next_x,next_y))
    return A_box

def check_A_and_B(A_box):
    # A_dfs()의 결과로 받은 set로 B 국기판을 돌아서 문자를 세트로 넣어여
    B_box = set()
    for x, y in A_box:
        B_box.add(B[x][y])

    return B_box

sero, garo = map(int, input().split())
dxy = [(0,1),(1,0),(0,-1),(-1,0)]
A = [list(map(str, input().strip())) for _ in range(sero)]
B = [list(map(str, input().strip())) for _ in range(sero)]
# A랑 B의 국기를 나누어서 받아요.
A_visited = [[0] * garo for _ in range(sero)]
# A의 방문 처리를 할 visited

for i in range(sero):
    for j in range(garo):
        if not A_visited[i][j]:
            A_box = A_dfs(i, j, A[i][j])
            # A를 dfs 돌아서 좌표를 담은 set를 받아요.
            B_box = check_A_and_B(A_box)
            # 그 받은 set로 함수를 돌아요. 여기서도 set로 반환 받아서,
            # 그 set의 크기가 1을 넘으면 다른 문자가 들어 갔다는 뜻이니까 똑같지 않다는 뜻!

            if len(B_box) != 1:
                print('NO')
                exit()
            # 그래서 여기서 크기로 비교합니다.

print('YES')

